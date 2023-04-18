#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int fib(int n);

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", fib(n));

    return 0;
}
int fib(int n)
{
    int a = 1, f1 = 1, f2 = 1, b = 0;
    if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 1;
    }
    else
    {
        for (a = 1; a <= n-2; a++)
        {
            b = f1 + f2;
            f1 = f2;
            f2 = b;
        }
        return b;

    }

}