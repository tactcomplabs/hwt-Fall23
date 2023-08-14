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

## Buiding the sample code

## Licensing

See the top-level LICENSE file

## Contact
* *John Leidel* - *Chief Scientist* - [Tactical Computing Labs](http://www.tactcomplabs.com)
