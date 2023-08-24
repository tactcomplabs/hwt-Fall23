//
// Copyright (C) 2017-2023 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

#include "clang/Basic/FileManager.h"
#include "clang/Frontend/CompilerInstance.h"
#include "llvm/ADT/StringMap.h"
#include "llvm/Support/raw_ostream.h"
#include <string>

using namespace clang;

#ifndef _CHALLENGE1_MSG_H_
#define _CHALLENGE1_MSG_H_

class Challenge1Msg {
private:

  // Functions
  void PrintInternalMsg(llvm::raw_ostream &ros,
                        const std::string Str){
    ros << Str << "\n";
  }

public:

  /// Default constructor
  Challenge1Msg() {}

  /// Default destructor
  ~Challenge1Msg() {}

  /// Prints a raw message
  void PrintRawMsg(std::string Str){
    PrintInternalMsg(llvm::outs(),Str);
  }

  /// Prints an error message
  void PrintErrMsg(std::string Str){
    PrintInternalMsg(llvm::errs(),Str);
  }

  /// Prints a warning message
  void PrintWarnMsg(std::string Str){
    PrintInternalMsg(llvm::outs(),Str);
  }

  /// Prints a debug message
  void PrintDebugMsg(std::string Str){
    PrintInternalMsg(llvm::outs(), "==> DEBUG : " + Str);
  }
};

#endif

// EOF
