#include "stdio.h"
#define N 100
struct student
{
    int id;
    char name[20];
    int kaoqun;
    int biaoxian;
    int zuoye;
    int biji;
    int sum;
} stud[N], t;
int main()
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        printf("请输入第%d个学生信息\n", i + 1);
        scanf("%d %s", &stud[i].id, &stud[i].name);
        fflush(stdin);
        scanf("%d %d %d %d", &stud[i].kaoqun, &stud[i].biaoxian, &stud[i].zuoye, &stud[i].biji);
        stud[i].sum = stud[i].kaoqun * 0.3 + stud[i].biaoxian * 0.3 + stud[i].zuoye * 0.3 + stud[i].biji * 0.1;
    } //排序
    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - 1 - i; j++)
        { //按成绩对学生信息进行排序
            if (stud[j].sum > stud[j + 1].sum)
            { //整型数字的比较
                t = stud[j];
                stud[j] = stud[j + 1];
                stud[j + 1] = t;
            }
        }
    } //打印
    printf("学号\t姓名\t考勤\t表现\t作业\t笔记\t总分\t\n");
    for (i = 0; i < N; i++)
    {
        printf("%d\t", stud[i].id);
        printf("%s\t", stud[i].name);
        printf("%d\t", stud[i].kaoqun);
        printf("%d\t", stud[i].biaoxian);
        printf("%d\t", stud[i].zuoye);
        printf("%d\t", stud[i].biji);
        printf("%d \n", stud[i].sum);
    }
    return 1;
}