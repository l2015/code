#include <stdio.h> 
#define n 20 //求解项数
int main()
{
   int i;//循环变量
   double a=2,b=1;//a,b分别为某项的分子、分母
   double  sum=0;
   double temp;//临时变量
   for (i=1;i<=n;i++)
      {
         sum+=a/b;
         temp=a;//记录前一项分子
         a=a+b;//前一项分子与分母之和为后一项分子
         b=temp;//前一项分子为后一项分母
      }
   printf("前%d项之和为:sum=%9.7f\n",n,sum);
   return 0;
}