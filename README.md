# Binary

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

What things you need to install the software and how to install them

```
cmake
ctest
make
g++
``` 

## Installation

```bash
cmake CMakeLists.txt 
make
```

## Tests

Required installation section.

```bash
ctest
```

## Usage

```
./binary option

 --help              Print help
 -d NUMBER SIZE      Print number in Sign-Magnitude representation
 -s NUMEBR SIZE      Print number in 2s Complement representation

 NUMBER:             Whole number (maximal size LONG INT)
 SIZE:               Number of bits (<1, 64>) or (CHAR, SHORT, INT, LONG_INT)
```

## Versioning

I use [Git](https://git-scm.com/) for versioning. For the versions available, see the [tags on this repository](https://github.com/Ratkovsky1/Binary/tags).

## Author

* **Lukas Ratkovsky** - *Initial work* - [Ratkovsky1](https://github.com/Ratkovsky1)

## License

See the [LICENSE](LICENSE) file for details