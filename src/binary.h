/*
 * Project: Printing numbers in binary system.
 * Author:  Lukas Ratkovsky
 * Version: 1.0
 */
typedef enum
{
  HELP,
  DK,
  SPK,
} options;

typedef struct
{
  long int number;
  long int size;
  options choose;
} Argum;

Argum checkArgument(int argc, char **argv);
_Bool convertSize(long int *number, char *string);
_Bool convertNumber(long int *number, char *string);

void printHelp(void);
void printBinary(long int number, unsigned long int pointer, short size);
void printDKBinary(long int number, short size);
void printSPKBinary(long int number, short size);
long int absLong(long int value);