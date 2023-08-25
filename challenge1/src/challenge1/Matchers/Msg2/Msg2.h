//
// Copyright (C) 2017-2023 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

//---------------
// clang headers
//---------------
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"
#include "clang/Basic/SourceManager.h"

//---------------
// CXX headers
//---------------
#include <variant>
#include <utility>
#include <string>

//---------------
// meta headers
//---------------
#include "../../Challenge1Lang.h"
#include "../../Challenge1Conf.h"
#include "../../Challenge1Msg.h"

using namespace clang;
using namespace ast_matchers;
using namespace diag;

#ifndef _CHALLENGE1_MSG2_H_
#define _CHALLENGE1_MSG2_H_

DeclarationMatcher VarMatcher = varDecl().bind("var-decl");

class Msg2 : public Challenge1Lang{
public:
  Msg2(clang::ASTContext *Ctx,
       clang::ast_matchers::MatchFinder &Finder,
       Challenge1Conf &Conf, Challenge1Msg &Msg)
    : Challenge1Lang(Ctx,Finder,Conf,Msg){

    // add the matchers
    Finder.addMatcher(VarMatcher, this);
  }

  void run(const clang::ast_matchers::MatchFinder::MatchResult &Result) override{

    if (const auto *V =
            Result.Nodes.getNodeAs<clang::VarDecl>("var-decl")) {
      std::string DeclName = "== VarDecl = " + V->getNameAsString() +
                             " @ " +
                             V->getBeginLoc().printToString(
                               getASTContext()->getSourceManager());
      Msg.PrintRawMsg(DeclName);
    }
  }

  void onEndOfTranslationUnit() override{}

  void PrintLangHelp() override{
    Msg.PrintRawMsg(" MSG2 OPTIONS");
    Msg.PrintRawMsg("*+----------------------------------------------------------+*");
    Msg.PrintRawMsg(" NONE");
    Msg.PrintRawMsg("*+----------------------------------------------------------+*");
  }

private:

};  // Msg2

#endif

// EOF
