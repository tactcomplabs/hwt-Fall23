# Top-Level CMake
#
# Copyright (C) 2017-2023 Tactical Computing Laboratories, LLC
# All Rights Reserved
# contact@tactcomplabs.com
#
# See LICENSE in the top level directory for licensing details
#
cmake_minimum_required(VERSION 3.4.3)
project(meta)
set(VERSION "0.1.0")

#------------------------------------------------------------------------
#-- SETUP PATHS
#------------------------------------------------------------------------
# Setup the path to the LLVM installation directory
set(CHALLENGE1_LLVM_INSTALL_DIR "" CACHE PATH "LLVM installation directory")

# Sanity check the path
set(CHALLENGE1_LLVM_INCLUDE_DIR "${CHALLENGE1_LLVM_INSTALL_DIR}/include/llvm")
if(NOT EXISTS "${CHALLENGE1_LLVM_INCLUDE_DIR}")
  message(FATAL_ERROR " CHALLENGE1_LLVM_INSTALL_DIR (${CHALLENGE1_LLVM_INCLUDE_DIR}) is invalid.")
endif()

#------------------------------------------------------------------------
#-- LOAD THE CONFIGURATION
#------------------------------------------------------------------------
list(APPEND CMAKE_PREFIX_PATH "${CHALLENGE1_LLVM_INSTALL_DIR}/lib/cmake/llvm/")
list(APPEND CMAKE_PREFIX_PATH "${CHALLENGE1_LLVM_INSTALL_DIR}/lib/cmake/clang/")

find_package(Clang REQUIRED CONFIG)

if(NOT "${LLVM_VERSION_MAJOR}" VERSION_GREATER_EQUAL "11")
  message(FATAL_ERROR "Found LLVM ${LLVM_VERSION_MAJOR}, but need a minimum of LLVM 11")
endif()

message(STATUS "Found Clang ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using ClangConfig.cmake in: ${CHALLENGE1_LLVM_INSTALL_DIR}")

message("CLANG STATUS:
  Includes (clang)    ${CLANG_INCLUDE_DIRS}
  Includes (llvm)     ${LLVM_INCLUDE_DIRS}"
)

include_directories(SYSTEM "${LLVM_INCLUDE_DIRS};${CLANG_INCLUDE_DIRS}")

#------------------------------------------------------------------------
#-- COMPILER OPTIONS
#------------------------------------------------------------------------
# enable C++ 14
set(CMAKE_CXX_STANDARD 14 CACHE STRING "")

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE
      STRING "Build type (default Debug):" FORCE)
endif()

# Set the debug flags
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_definitions(-DCHALLENGE1_DEBUG)
  if(CHALLENGE1_DEBUG_AST)
    add_definitions(-DCHALLENGE1_DEBUG_AST)
  endif()
endif()

# set the compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -fdiagnostics-color=always -ftemplate-depth=2048")

if(NOT LLVM_ENABLE_RTTI)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-rtti")
endif()

# -fvisibility-inlines-hidden is set when building LLVM and on Darwin warnings
# are triggered if llvm-tutor is built without this flag (though otherwise it
# builds fine). For consistency, add it here too.
include(CheckCXXCompilerFlag)
check_cxx_compiler_flag("-fvisibility-inlines-hidden" SUPPORTS_FVISIBILITY_INLINES_HIDDEN_FLAG)
if (${SUPPORTS_FVISIBILITY_INLINES_HIDDEN_FLAG} EQUAL "1")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fvisibility-inlines-hidden")
endif()

# Set the build directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

#------------------------------------------------------------------------
#-- TESTING
#------------------------------------------------------------------------
# Enable testing
enable_testing()

#------------------------------------------------------------------------
#-- SUBDIRECTORIES
#------------------------------------------------------------------------
# Add subdirectories
add_subdirectory(src)
add_subdirectory(test)

# EOF
