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
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/Basic/SourceManager.h"

//-------------------
// Challenge1 Headers
//-------------------
#include "Challenge1Msg.h"
#include "Challenge1Conf.h"

// --------------------------
// Challenge1 Matcher Headers
// --------------------------
#include "Matchers/Msg1/Msg1.h"
#include "Matchers/Msg2/Msg2.h"

using namespace clang;

#ifndef _CHALLENGE1_ASTLIB_H_
#define _CHALLENGE1_ASTLIB_H_

class Challenge1ASTLib : public clang::ast_matchers::MatchFinder::MatchCallback {
public:
  /// default constructor
  Challenge1ASTLib(clang::ASTContext *Ctx,
                   clang::ast_matchers::MatchFinder &Finder,
                   Challenge1Conf &Conf,
                   Challenge1Msg &Msg){

    // enable all the ast handlers
    if( Conf.isMsg1() ){
      EnabledLangs.push_back(static_cast<Challenge1Lang *>(
          new Msg1(Ctx,Finder,Conf,Msg)));
    }

    if( Conf.isMsg2() ){
      EnabledLangs.push_back(static_cast<Challenge1Lang *>(
          new Msg2(Ctx,Finder,Conf,Msg)));
    }

    // determine if we should print the language-specific help menus
    if( Conf.isHelpEnabled() ){
      for( auto Lang : EnabledLangs ){
        Lang->PrintLangHelp();
      }
    }
  }

  /// default destructor
  ~Challenge1ASTLib(){
    for( auto Lang : EnabledLangs ){
      delete Lang;
    }
  }

  /// executes the AST matchers
  void run(const clang::ast_matchers::MatchFinder::MatchResult &) override{
    // do nothing
  }

  /// completes the translation unit
  void onEndOfTranslationUnit() override{
    // do nothing
  }
private:
  llvm::SmallVector<Challenge1Lang *,5> EnabledLangs; ///< Enabled AST handlers
};

#endif

// EOF
