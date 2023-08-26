// RUN: clang++ -cc1 -load %shlibdir/libChallenge1Lib%shlibext -plugin Challenge1 \
// RUN: -plugin-arg-Challenge1 -enable-msg2 %s 2>&1
//
// Copyright (C) 2017-2023 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//


int main(int argc, char **argv){
  unsigned VAR1;
  unsigned VAR2;
  unsigned long VAR3;
  unsigned long long VAR4;
  float VAR5;
  double VAR6;
  bool VAR7;
  int *VAR9;
  void *VAR10;
  return 0;
}

// EOF
