# CHALLENGE1 src/challenge1/CMakeLists.txt
#
# Copyright (C) 2017-2023 Tactical Computing Laboratories, LLC
# All Rights Reserved
# contact@tactcomplabs.com
#
# See LICENSE in the top level directory for licensing details
#

#------------------------------------------------------------------------
# Setup the source requirements
#------------------------------------------------------------------------
set(Challenge1_SOURCES
  Challenge1Lib.cpp
  Challenge1ASTLib.h
  Challenge1Msg.h
  Challenge1Conf.h
  Challenge1Lang.h
)

#------------------------------------------------------------------------
# Add the subdirectory containing the matcher support
#------------------------------------------------------------------------
add_subdirectory(Matchers)

#------------------------------------------------------------------------
# Setup the library target
#------------------------------------------------------------------------
include_directories(.)
add_library(Challenge1Lib SHARED ${Challenge1_SOURCES}
                                 $<TARGET_OBJECTS:Msg1Objs>
                                 $<TARGET_OBJECTS:Msg2Objs>
           )

target_compile_options(Challenge1Lib PRIVATE -fPIC)

# On Darwin (unlike on Linux), undefined symbols in shared objects are not
# allowed at the end of the link-edit. The plugins defined here:
#  - _are_ shared objects
#  - reference symbols from LLVM shared libraries, i.e. symbols which are
#    undefined until those shared objects are loaded in memory (and hence
#    _undefined_ during static linking)
# The build will fail with errors like this:
#    "Undefined symbols for architecture x86_64"
# with various LLVM symbols being undefined. Since those symbols are later
# loaded and resolved at runtime, these errors are false positives.
# This behaviour can be modified via the '-undefined' OS X linker flag as
# follows.
target_link_libraries(Challenge1Lib
                      "$<$<PLATFORM_ID:Darwin>:-undefined dynamic_lookup>" )

install(TARGETS Challenge1Lib DESTINATION lib)

# EOF
