#include <stdio.h>
int main()
{
    float h = 100;
    float hsum;
    for (int times = 0; times < 10; times++)
        {
            h = h / 2; 
            hsum = hsum + 2 * h;
        }
    hsum = hsum + 100;
    printf("共经过:%fm\n第十次反弹:%fm", hsum, h);
}