#include <stdio.h>

int main()
{
    void hanoi(int n, char one, char two, char three);
    int x;
    printf("input numbers of distakes : ");
    scanf("%d", &x);
    printf("step : \n");
    hanoi(x, 'A', 'B', 'C');
}

void hanoi(int n, char one, char two, char three)
{
    void mov(char x, char y);
    if (n == 1)
    {
        mov(one, three);
    }
    else
    {
        hanoi(n - 1, one, three, two);
        mov(one, three);
        hanoi(n - 1, two, one, three);
    }
}

void mov(char x, char y)
{
    printf("%c->%c\n", x, y);
}