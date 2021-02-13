#  Homo Deus - C Library

## Introduction

The Homo Deus C Library (hdelibc) is an open source collection of tools for the C programming language.  
The project is in continuous development, with features being added and revised continually over time.  

## Compiling

If you save the hdelibc directory to your default include location, there is no need to compile anything; however, a makefile is provided to allow the compiling of hdelibc into a static library containing all sub-modules, individual sub-modules, or both.  The simplest configuration is to compile both with the command:

```
make
```

This will generate a static library for hdelibc as a whole, as well as static libraries for each of the sub-modules individually.  If you only wish to compile the top-level static library, use:

```
make Main
```

If you wish to compile a static library for only a portion of hdelibc, you will need to use the command specified for that section.  You can find the command in that sub-module's README, or in the table of contents below.

## Including

The easiest way to import the library is simply to download the project folder and copy it into your project, and then reference the desired header files.  You will need to use brackets or quotes according to how you intend to use the library, but documentation is written as if hdelibc is saved in your default include path.

```
// If in default include path:
#include <hdelibc.h>
// If in the same directory as your project:
#include "hdelibc/hdelibc.h"
```

If you are using hdelibc as a static library, remember to include the desired .a file in your command:

```
gcc my_project.c hdelibc/hdelibc.a
```

If only a section of the library is desired, that section alone may be included, and static libraries are provided for each sub-module.  
Again, use the include statement and parameterize the static library (if applicable):

```
#include <hdelibc/DataStructures/DataStructures.h>
```

```
gcc my_project.c hdelibc/DataStructures/DataStructures.a
```

Since there are numerous sub-modules, this file will simply serve as a table of contents for what is included in the library. 

## Contents

For specific documentation on components, check the README included in the sub-module directories.  

### Data Structures

**Location:**

```
~/hdelibc/DataStructures
```

**Include:**

```
#include <hdelibc/DataStructures/hdelibc-datastructures.h>
```


#### Components

**Common**

* Node

**Dictionary**

* Entry
* Dictionary

**Lists**

* LinkedList
* Queue

**Trees**

* BinarySearchTree
