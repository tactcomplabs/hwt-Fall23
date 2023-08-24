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
#include "Challenge1Conf.h"
#include "Challenge1Msg.h"

using namespace clang;
using namespace ast_matchers;

#ifndef _CHALLENGE1_LANG_H_
#define _CHALLENGE1_LANG_H_

class Challenge1Lang : public clang::ast_matchers::MatchFinder::MatchCallback {
public:
  // public methods

  /// Default constructor
  Challenge1Lang(clang::ASTContext *Ctx,
                 clang::ast_matchers::MatchFinder &Finder,
                 Challenge1Conf &Conf, Challenge1Msg &Msg)
    : Ctx(Ctx), Conf(Conf), Msg(Msg){
  }

  /// Default destructor
  ~Challenge1Lang(){}

  /// Get a fully qualified name for an expression
  std::string getFullyQualifiedStr(const Expr *expr,
                                   const ASTContext &Context) {
    static PrintingPolicy print_policy(Context.getLangOpts());
    print_policy.FullyQualifiedName = 1;
    print_policy.SuppressScope = 0;
    print_policy.PrintCanonicalTypes = 1;
    std::string expr_string;
    llvm::raw_string_ostream stream(expr_string);
    expr->printPretty(stream, nullptr, print_policy);
    stream.flush();
    return expr_string;
  }

  /// Retrieve the AST context
  clang::ASTContext *getASTContext() { return Ctx; }

  /// Build the name of the target node
  std::string BuildNodeName(std::string Base, CallExpr const *ce){
    std::string PathName = ce->getBeginLoc().printToString(
      getASTContext()->getSourceManager());

    std::string ParName = Base + " " +
      PathName.substr(PathName.find_last_of("/\\") + 1);
    return ParName;
  }

  // public data
  clang::ASTContext *Ctx;       ///< Clang AST Context
  Challenge1Conf &Conf;         ///< Configuration object
  Challenge1Msg &Msg;           ///< Messaging object

  /// virtual methods
  virtual void PrintLangHelp() {}
};

#endif

// EOF
