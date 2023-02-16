// 1_시작.c
// https://github.com/yoondev-classroom/hyundai_230216

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

//  a.c -> IL -> a.o
// Java,jython, jRuby, Closure
//  - Write Once, Run Anywhere
//  Sample.java -> Sample.class <= java(가상 머신)
//                 - Byte Code
// C#/VB/C++/F#
//  Sample.cs   -> Sample.obj   <= CLR(가상 머신)
//                 - IL

#include <stdio.h>
// 표준 입출력 라이브러리

// a.exe   -> 실행중인 프로그램
// 프로그램      "프로세스"

// 키보드: 표준 입력장치 => stdin
// 모니터: 표준 출력장치 => stdout
// 모니터: 표준 에러장치 => stderr

// stdout vs stderr: 버퍼링

#if 0
int main(void)
{
  fprintf(stderr, "Hello, C\n");

  // fprintf(stdout, "Hello, C\n");
  // printf("Hello, C\n");
  return 0;
}
#endif

int main(void)
{
  // printf("Hello\n");
  fprintf(stderr, "Hello");
  while (1)
    ;
}