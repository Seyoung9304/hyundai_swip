// 7_제어문3.c
#include <stdio.h>

// do-while
// : 무조건 1번은 실행해야 할 때...

#if 0
int main(void)
{
  int n;
  scanf("%d", &n);

  while (n < 10)
  {
    scanf("%d", &n);
  }

  printf("%d\n", n);

  return 0;
}
#endif

#if 0
int main(void)
{
  int n;

  do
  {
    scanf("%d", &n);
  } while (n < 10);

  printf("%d\n", n);

  return 0;
}
#endif

//---------
// 중첩된 루프 탈출을 위해 flag 같은 방법을 사용했습니다.

#if 0
int main(void)
{
  int x[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int flag = 0;

  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (x[i][j] == 3)
      {
        flag = 1;
        break;
      }

      printf("%d ", x[i][j]);
    }

    printf("\n");
    if (flag)
    {
      break;
    }
  }

  printf("program end\n");
  return 0;
}
#endif

// goto
// - 코드의 흐름을 분석하기 어렵게 만들 수 있기 때문에
//   goto를 사용할 때 주의해야 합니다.
// > 이미 실행된 코드로 다시 점프하는 것은 금지해야 합니다.
#if 0
int main(void)
{
  int n;
  scanf("%d", &n);

  if (n == 10)
  {
    goto aaa;
  }

before:
  printf("hello\n");
  printf("hello\n");
  printf("hello\n");

aaa:
  printf("hello\n");

  if (n == 1)
  {
    goto before; /* 금지! */
  }

  return 0;
}
#endif

// goto 유용할 때 2가지
//  1) 중첩된 반복문의 탈출에 유용합니다.
#if 0
int main(void)
{
  int x[2][3] = {{1, 2, 3}, {4, 5, 6}};

  for (int i = 0; i < 2; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      if (x[i][j] == 3)
      {
        goto out;
      }

      printf("%d ", x[i][j]);
    }

    printf("\n");
  }

out:
  printf("program end\n");
  return 0;
}
#endif

// 2) 오류 처리 루틴의 코드 중복을 제거할 수 있습니다.
#if 0
void foo(void)
{
  FILE *fp1 = fopen("a.txt", "r");
  if (fp1 == NULL)
  {
    return;
  }

  FILE *fp2 = fopen("b.txt", "r");
  if (fp2 == NULL)
  {
    fclose(fp1);
    return;
  }

  FILE *fp3 = fopen("c.txt", "r");
  if (fp3 == NULL)
  {
    fclose(fp2);
    fclose(fp1);
    return;
  }

  fclose(fp3);
  fclose(fp2);
  fclose(fp1);
}
#endif

void foo(void)
{
  FILE *fp1 = fopen("a.txt", "r");
  if (fp1 == NULL)
  {
    goto out1;
  }

  FILE *fp2 = fopen("b.txt", "r");
  if (fp2 == NULL)
  {
    goto out2;
  }

  FILE *fp3 = fopen("c.txt", "r");
  if (fp3 == NULL)
  {
    goto out3;
  }

  fclose(fp3);
out3:
  fclose(fp2);
out2:
  fclose(fp1);
out1:
}

int main(void)
{
  foo();

  return 0;
}