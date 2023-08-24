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
#include "Matchers/Msg1.h"
#include "Matchers/Msg2.h"

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
  }

  /// default destructor
  ~Challenge1ASTLib(){
  }

  /// executes the AST matchers
  void run(const clang::ast_matchers::MatchFinder::MatchResult &) override{
    // do nothing
  }

  /// completes the translation unit
  void onEndOfTranslationUnit() override{
    // do nothing
  }
};

#endif

// EOF
