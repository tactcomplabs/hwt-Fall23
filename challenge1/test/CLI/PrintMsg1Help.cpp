// test the msg1 help menu

// RUN: clang++ -cc1 -load %shlibdir/libChallenge1Lib%shlibext -plugin Challenge1 \
// RUN: -plugin-arg-Challenge1 -enable-msg1 -plugin-arg-Challenge1 -help %s 2>&1
