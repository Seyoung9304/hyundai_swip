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
// 4. 표준 입출력 라이브러리
// printf
// scanf
// fprintf
// fscanf

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

#if 0
int main(void)
{
  // printf("Hello\n");
  fprintf(stderr, "Hello");
  while (1)
    ;
}
#endif

// 5. main 함수
//  => 프로그램이 시작할 때, 가장 먼저 수행되는 함수입니다.
//    - Entry Point
//   1) 프로그램 내에 오직 한개만 존재해야 합니다.
//   2) main의 종료는 프로그램의 종료입니다.
//   3) main 형태
//    - int main(void)
//    - int main(int argc, char** argv) => 명령행 인자

// 6. 함수의 형태
// 함수의_반환_타입 함수의_이름(함수의_입력_타입 함수의_입력_타입_변수명)
// int add(int a, int b) { return a + b; }

int main(void)
{
  printf("Hello, C\n");
  return 0;
  // 7.  main의 반환값 => 프로세스의 결과
  //   0은 성공을 의미합니다.
  //   0이 아닌값은 실패 코드를 의미합니다.
}