//
// Copyright (C) 2017-2023 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

//---------------
// Clang Headers
//---------------

#include "clang/Basic/FileManager.h"
#include "clang/Frontend/CompilerInstance.h"
#include "llvm/ADT/StringMap.h"
#include "llvm/Support/raw_ostream.h"

//-------------------
// Challenge1 Headers
//-------------------

#include "Challenge1Msg.h"

//---------------
// CXX Headers
//---------------

#include <vector>
#include <string>

using namespace clang;

#ifndef _CHALLENGE1_CONF_H_
#define _CHALLENGE1_CONF_H_

class Challenge1Conf {
private:

  Challenge1Msg Msg;      ///< messaging object

  bool EnableHelp;        ///< enables the help message
  bool EnableMsg1;        ///< enables msg1 generation
  bool EnableMsg2;        ///< enables msg2 generation

public:

  /// default constructor
  Challenge1Conf()
    : EnableHelp(false),
      EnableMsg1(false),
      EnableMsg2(false){
  }

  /// default destructor
  ~Challenge1Conf(){
  }

  /// is the help enabled?
  bool isHelpEnabled() { return EnableHelp; }

  /// is msg1 enabled?
  bool isMsg1() { return EnableMsg1; }

  /// is msg2 enabled?
  bool isMsg2() { return EnableMsg2; }

  /// parse the incoming args
  bool ParseArgs(const CompilerInstance &CI,
                 const std::vector<std::string> &Args){
    for(StringRef Arg : Args){
      if( Arg.startswith("-help") ){
        PrintHelp();
        EnableHelp = true;
      }else if( Arg.startswith("-enable-msg1") ){
        EnableMsg1 = true;
      }else if( Arg.startswith("-enable-msg2") ){
        EnableMsg2 = true;
      }else{
        Msg.PrintRawMsg("Unknown command line option");
        return false;
      }
    }
    return true;
  }

  /// print the help menu
  void PrintHelp(){
    Msg.PrintRawMsg("*+----------------------------------------------------------+*");
    Msg.PrintRawMsg("*+                   CHALLENGE1                             +*");
    Msg.PrintRawMsg("*+----------------------------------------------------------+*");
    Msg.PrintRawMsg(" -help                      : Prints the help menu");
    Msg.PrintRawMsg(" -enable-msg1               : Enables Msg1 support");
    Msg.PrintRawMsg(" -enable-msg2               : Enables Msg2 support");
    Msg.PrintRawMsg("*+----------------------------------------------------------+*");
  }
};

#endif

// EOF
