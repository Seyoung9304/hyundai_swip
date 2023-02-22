// 14_함수포인터5.c
#include <stdio.h>
//
// 1. 함수의 타입은 함수의 시그니처에 의해 결정됩니다.
//    함수의 인자정보가 동일하고 반환타입이 동일하면 같은 함수 타입이다.
//    같은 타입의 함수 포인터를 통해 참조할 수 있습니다.

// 버튼 라이브러리를 만들어봅시다.
struct button
{
  char name[32];

  void (*onClick)(void);
};

void touchUpInside(struct button *button)
{
  printf("button clicked: %s\n", button->name);

  if (button->onClick)
  {
    button->onClick();
  }
}

void save(void)
{
  printf("저장되었습니다..\n");
}

void quit(void)
{
  printf("종료되었습니다.\n");
}

void setOnClickButton(struct button *button,
                      void (*f)(void))
{
  button->onClick = f;
}

int main(void)
{
  struct button saveButton = {"저장"};
  struct button exitButton = {"종료"};

  setOnClickButton(&saveButton, save);
  setOnClickButton(&exitButton, quit);

  touchUpInside(&saveButton);
  touchUpInside(&exitButton);

  return 0;
}

#if 0
void foo(void) // void(void)
{
  printf("foo\n");
}

void goo(void) // void(void)
{
  printf("goo\n");
}
#endif