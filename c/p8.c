#include <stdio.h>
int main()
{
    int m, a, b, c;
    // scanf("%d", &m);

    for (m = 100; m < 1000; m++)
    {
        a = m / 100 % 10;
        b = m / 10 % 10;
        c = m % 10;
        if (m == (a * a * a + b * b * b + c * c * c))
            printf("%d是一个水仙花数\n", m);
        continue;
    }

    // printf("%d", a);
}