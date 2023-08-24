# HackWesTex/Tactical Computing Labs Challenge #1

## Overview

The Clang/LLVM compiler infrastructure provides the ability to integrate 
external plugins in order to process additional language features, perform 
frontend optimizations and lint source code.  These plugins are loaded 
during compiler invocation and have the ability to output compilation 
messages and data using the standard Clang/LLVM messaging infrastructure.  

This challenge seeks to integrate these plugin-specific messages and 
output data with the Microsoft VSCode development infrastructure.  VSCode 
provides a wealth of flexibility when developing with different languages 
using different backend tools.  We seek to intgrate our plugin specific 
output directly with the VSCode UI.

## Requirements

There are a number of basic requirements for this challenge, including:
* You must use the Clang/LLVM compiler version specified below.
* The code must be integrated with the standard (free) Microsoft VSCode infrastructure.
* Any external plugins utilized must be MIT, BSD or Apache licensed.  No GPL-3 code 
will be accepted

Additionally, we set forth the following additional technical requirements:
* First, you must be able to enable/disable the plugin from within the VSCode
environment.  Users should not be required to manually edit makefiles.
* Second, the examples provided herein are C++ source code examples.  These MUST 
work from within VSCode.
* Third, you can implement the VSCode changes, plugins, etc can be implemented 
in whatever manner that is appropriate
* Finally, output from the plugin (formats, etc) can be changed if necessary.

Be creative!  Matching output messages back to source code lines could 
be interesting.  Additional visualizations will be given additional points/consideration 
when judging the final deliverables.

## Deliverables

The deliverables for this challenge include:
* A working demo of your integrated VSCode infrastructure.  We must see it work!
* Any source code changes to the sample Clang plugin.  We don't anticipate changes, 
but if you do anything such as add candidate output data formats, these must be 
submitted.
* Any source code associated with the solution (scripts, etc)
* Concise documentation to build, integrate and test the solution.  This should also 
include any required external packages outside of what is outlined above.

## Dependencies
* Clang+LLVM Compiler Infrastructure (tested on 11+)
* Lit Test Harnes
* VSCode
* CMake 3.4.3+

On MacOS:
```
brew install llvm@11
brew install lit
```

On Ubuntu:
```
wget https://apt.llvm.org/llvm.sh
chmod +x llvm.sh
sudo ./llvm.sh
sudo pip3 install lit
```

On Windows:
```
Good luck...
```

## Buiding the sample code

Building+Testing on MacOS:

```
git clone https://github.com/tactcomplabs/hwt-Fall23.git
cd hwt-Fall23/challenge1
mkdir build
cd build
cmake -DCHALLENGE1_LLVM_INSTALL_DIR=/usr/local/opt/llvm@11 ../
make -j
lit ./test
```

Building+Testing on Ubuntu:

```
git clone https://github.com/tactcomplabs/hwt-Fall23.git
cd hwt-Fall23/challenge1
mkdir build
cd build
cmake -DCHALLENGE1_LLVM_INSTALL_DIR=/usr/lib/llvm-11/ ../
make -j
lit ./test
```

Running tests outside of the `lit` test harness is simple, but requires 
a number of pertinent command line options.  The following example was 
executed on MacOS where the `hwt-Fall23` directory was located in the 
user's $HOME directory.  The command line options include:

* `-cc1` : enable the Clang compiler
* `-load ~hwt-Fall23/challenge1/build/lib/libChallenge1Lib.dylib` : load the 
external plugin lirbary.  Note the file extension.  On Ubuntu, this will be `.so`, not 
`.dylib`
* `-plugin Challenge1` : enables the plugin
* ` -plugin-arg-Challenge1 -help` : passes a SINGLE argument to the plugin
* `~/hwt-Fall23/challenge1/test/CLI/PrintHelp.cpp` : path to the CXX file

```
/usr/local/opt/llvm@11/bin/clang++ -cc1 -load ~/hwt-Fall23/challenge1/build/lib/libChallenge1Lib.dylib -plugin Challenge1  -plugin-arg-Challenge1 -help ~/hwt-Fall23/challenge1/test/CLI/PrintHelp.cpp
```

## Licensing

See the top-level LICENSE file

## Contact
* *John Leidel* - *Chief Scientist* - [Tactical Computing Labs](http://www.tactcomplabs.com)
