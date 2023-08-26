// RUN: clang++ -cc1 -load %shlibdir/libChallenge1Lib%shlibext -plugin Challenge1 \
// RUN: -plugin-arg-Challenge1 -enable-msg1 -plugin-arg-Challenge1 -enable-msg2 %s 2>&1
//
// Copyright (C) 2017-2023 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

int FOO(int i){
  if( (i>10) && (i<100) ){
    return i++;
  }
  return i+3;
}

int BAR(int i){
  return FOO(i);
}

int main(int argc, char **argv){
  return BAR(argc);
}

// EOF
