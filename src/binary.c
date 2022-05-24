/*
 * Project: Printing numbers in binary system.
 * Author:  Lukas Ratkovsky
 * Version: 1.0
 */
#include "binary.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

const short MIN_ARGUMENT_COUNT = 1;
const short MAX_ARGUMENT_COUNT = 3;
const short MIN_BITS_COUNT = 1;
const short MAX_BITS_COUNT = sizeof(long int) * 8;

int main(int argc, char *argv[])
{
	Argum verdict = checkArgument(argc - 1, argv);
	switch (verdict.choose)
	{
	case DK:
		printDKBinary(verdict.number, (short)verdict.size);
		break;
	case SPK:
		printSPKBinary(verdict.number, (short)verdict.size);
		break;
	case HELP:
	default:
		printHelp();
		break;
	};
	return errno;
}

Argum checkArgument(int argumentsCount, char **argv)
{
	Argum verdict = {0, 0, HELP};

	if (argumentsCount < MIN_ARGUMENT_COUNT || argumentsCount > MAX_ARGUMENT_COUNT)
	{
		errno = EINVAL;
		return verdict;
	}

	if (strcmp(argv[1], "--help") == 0 && argumentsCount == 1)
	{
		return verdict;
	}

	if (strcmp(argv[1], "-d") == 0 && argumentsCount == 3)
	{
		_Bool status = convertNumber(&(verdict.number), argv[2]) && convertSize(&(verdict.size), argv[3]);
		if (status == true && verdict.size >= MIN_BITS_COUNT && verdict.size <= MAX_BITS_COUNT)
		{
			verdict.choose = DK;
			return verdict;
		}
	}

	if (strcmp(argv[1], "-s") == 0 && argumentsCount == 3)
	{
		_Bool status = convertNumber(&(verdict.number), argv[2]) && convertSize(&(verdict.size), argv[3]);
		if (status == true && verdict.size >= MIN_BITS_COUNT && verdict.size <= MAX_BITS_COUNT)
		{
			verdict.choose = SPK;
			return verdict;
		}
	}

	errno = EINVAL;
	return verdict;
}

_Bool convertSize(long int *number, char *string)
{
	if (strcmp(string, "CHAR") == 0)
	{
		*number = sizeof(char) * 8;
		return true;
	}
	if (strcmp(string, "SHORT") == 0)
	{
		*number = sizeof(short) * 8;
		return true;
	}
	if (strcmp(string, "INT") == 0)
	{
		*number = sizeof(int) * 8;
		return true;
	}
	if (strcmp(string, "LONG_INT") == 0)
	{
		*number = sizeof(long int) * 8;
		return true;
	}
	return convertNumber(number, string);
}

_Bool convertNumber(long int *number, char *string)
{
	char *error_numb;
	*number = strtol(string, &error_numb, 10);

	if (*error_numb != '\0' || errno == ERANGE)
	{
		errno = ERANGE;
		return false;
	}
	else
	{
		return true;
	}
}

void printHelp(void)
{
	printf("./binary option\n\n"
		   " --help              Print help\n"
		   " -d NUMBER SIZE      Print number in Sign-Magnitude representation\n"
		   " -s NUMEBR SIZE      Print number in 2's Complement representation\n"
		   "\n"
		   " NUMBER:             Whole number (maximal size LONG INT)\n"
		   " SIZE:               Number of bits (<1,%d>) or (CHAR, SHORT, INT, LONG_INT)\n", MAX_BITS_COUNT);
}

void printDKBinary(long int number, short size) //  < -(2^(N-1))   , +(2^(N-1)-1) >
{
	short shiftCount = size - 1;
	unsigned long int maxNumberForSize = (1UL << shiftCount) - 1;
	if (number < 0)
	{
		if ((unsigned long int)absLong(number) > maxNumberForSize + 1)
		{
			errno = ERANGE;
			return;
		}
	}
	else
	{
		if ((unsigned long int)number > maxNumberForSize)
		{
			errno = ERANGE;
			return;
		}
	}
	printBinary(number, maxNumberForSize + 1, shiftCount);
}

void printSPKBinary(long int number, short size) // < -(2^(N-1)-1) , +(2^(N-1)-1) >
{
	short shiftCount = size - 1; // MSB's sign. Size must therefore be reduced by 1.
	unsigned long int maxNumberForSize = (1UL << shiftCount) - 1;
	char sign = number < 0 ? '1' : '0'; //  '-' = '1'; '+' = '0'
	number = absLong(number);
	if ((unsigned long int)number > maxNumberForSize)
	{
		errno = ERANGE;
		return;
	}

	printf("%c", sign);
	printBinary(number, (maxNumberForSize + 1) >> 1, shiftCount - 1);
}

void printBinary(long int number, unsigned long int pointer, short shiftCount)
{
	while (pointer > 0)
	{
		printf("%ld", (pointer & number) >> shiftCount);
		shiftCount--;
		pointer >>= 1;
	}
}

long int absLong(long int value)
{
	return value < 0 ? value * -1 : value;
}