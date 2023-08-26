// RUN: clang++ -cc1 -load %shlibdir/libChallenge1Lib%shlibext -plugin Challenge1 \
// RUN: -plugin-arg-Challenge1 -enable-msg2 %s 2>&1
//
// Copyright (C) 2017-2023 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

class Foo{
public:
  Foo(){}
  ~Foo(){}
  unsigned getA() { return A; }

private:
  unsigned A;
};

int main(int argc, char **argv){
  Foo A;
  unsigned B = A.getA();
  return 0;
}

// EOF
