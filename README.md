#### _____________________________________________________________________________
#### Copyright (C) 2017 by Alex Fosdick - University of Colorado

#### Redistribution, modification or use of this software in source or binary
#### forms is permitted as long as the files maintain this copyright. Users are 
#### permitted to modify this and use it to learn about the field of embedded
#### software. Alex Fosdick and the University of Colorado are not liable for
#### any misuse of this material. 
#### _____________________________________________________________________________

#### _____________________________________________________________________________
#### This is a free access repository for the Coursera Specialization of Embedded
#### Software Essentials to use in conjunction with the course1, the Introductio
#### to Embedded Software and Development Environments.
#### _____________________________________________________________________________

#### _____________________________________________________________________________
#### The repository is organized in multiple folders:
####      Makefile -> Build system for the project with debug flags
####      sources.mk -> Contains path to headers and includes
####      msp432p401r.lds -> Linker file for the msp432p401r microcontroller
####      src/ -> (Directory) Contains all the source files for the project 
####      include/ -> (Directory) Contains header files required for the project
#### _____________________________________________________________________________

#### _____________________________________________________________________________
####  USAGE

#### For verbose output and course1() enabled
##### ```make build DEBUGFLAG=-DVERBOSE COURSE1FLAG=-DCOURSE1```

#### For verbose output
##### ```make build DEBUGFLAG=-DVERBOSE```

#### For course1() enabled
##### ```make build COURSE1FLAG=-DCOURSE1```
#### _____________________________________________________________________________