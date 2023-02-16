// 1_시작.c
// https://github.com/yoondev-classroom/hyundai_230216
#include <stdio.h>

// 1. Compile 과정
//    전처리     -> 컴파일            ->  링크 -> a.exe / a.out(프로그램)
// #define      a.c -> a.o / a.obj
// #include     b.c -> b.o
// => 텍스트 처리

// 2.       Compile: Ctrl + F7
//    Compile + Run: Ctrl + F5

// 3. 컴파일러
// - Microsoft Visual C/C++ Compiler: cl.exe => MSVC
// - GNU C/C++ Compiler: gcc => GCC
// - LLVM Compiler: clang

int main(void)
{
  printf("Hello, C\n");
  return 0;
}