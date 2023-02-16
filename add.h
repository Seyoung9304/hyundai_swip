// 헤더파일이 중복 포함되는 것을 방지합니다.
// 1. #pragma once => 표준 X
// 2. include guard

#ifndef ADD_H_
#define ADD_H_

// add.h
extern void foo(void);
extern void goo(void);

extern int global;
// extern int internal_global;

struct AAA
{
};
// ODR: One Difinition Rule

#endif