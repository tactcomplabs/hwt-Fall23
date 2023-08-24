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
#include "clang/Basic/FileManager.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendPluginRegistry.h"
#include "llvm/ADT/StringMap.h"
#include "llvm/Support/raw_ostream.h"
#include "clang/Basic/SourceManager.h"

#include "clang/ASTMatchers/ASTMatchFinder.h"
#include "clang/ASTMatchers/ASTMatchers.h"

#include "clang/Rewrite/Core/Rewriter.h"

//-------------------
// Challenge1 Headers
//-------------------
#include "Challenge1Conf.h"
#include "Challenge1Msg.h"
#include "Challenge1ASTLib.h"

using namespace clang;

//-----------------------------------------------------------------------------
// ASTConsumer
//-----------------------------------------------------------------------------
class Challenge1ASTConsumer : public clang::ASTConsumer {
public:
  Challenge1ASTConsumer(clang::ASTContext *Ctx, clang::SourceManager &SM,
                        Challenge1Conf &Conf,
                        Challenge1Msg &Msg)
  : MatcherHandler(Ctx,Finder,Conf,Msg) {}

  void HandleTranslationUnit(clang::ASTContext &Ctx) override{
    Finder.matchAST(Ctx);
  }

private:
  clang::ast_matchers::MatchFinder Finder;        ///< AST matcher
  Challenge1ASTLib MatcherHandler;                ///< Matcher handler objects
};

//-----------------------------------------------------------------------------
// FrontendAction
//-----------------------------------------------------------------------------
class Challenge1 : public clang::PluginASTAction {
private:
  Challenge1Msg  Msg;     ///< messaging interface for console messages
  Challenge1Conf Conf;    ///< configuration infrastructure

public:
  std::unique_ptr<clang::ASTConsumer>
  CreateASTConsumer(clang::CompilerInstance &Compiler,
                    llvm::StringRef InFile) override {
    return std::unique_ptr<clang::ASTConsumer>(
        std::make_unique<Challenge1ASTConsumer>(&Compiler.getASTContext(),
                                                Compiler.getSourceManager(),
                                                Conf,Msg));
  }

  /// Parse the Clang plugin command line arguments
  bool ParseArgs(const CompilerInstance &CI,
                 const std::vector<std::string> &Args) override {
    return Conf.ParseArgs(CI,Args);
  }
};

//-----------------------------------------------------------------------------
// Plugin Registration
//-----------------------------------------------------------------------------
static FrontendPluginRegistry::Add<Challenge1>
  X("Challenge1",
    "Challenge1: Sample external Clang plugin for AST analysis");
// EOF
