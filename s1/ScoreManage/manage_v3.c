#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 学生结构体
struct Student
{
    char Name[10];
    float Chinese;
    float Math;
    float English;
    float Total;
    float Ave;
};

// 全局变量
int num;                 // 学生的人数
struct Student stu[100]; // 存储学生信息的数组

// 函数声明
void Input();                     // 输入学生成绩
void Show();                      // 输出每名学生的各科考试成绩和个人平均分
void Sort();                      // 总分排序
int SubMax(int Arr[], int num);   // 计算某一科目的最高分
float SubAve(int Arr[], int num); // 计算某一科目的平均分

int main()
{
    system("clear");
    printf("欢迎来到期末成绩管理系统v0.3\n\nby:李龙宇\n\n");
    Input();
    Show();
    Sort();
    return 0;
}

// 输入学生成绩
void Input()
{
        printf("请输入学生的人数:");
        scanf("%d", &num);

        int i;
        int cArr[num], eArr[num], mArr[num];
        for (i = 0; i < num; i++)
        {
            printf("请输入第%d个学生的姓名:", i + 1);
            scanf("%s", stu[i].Name);
            printf("请输入第%d个学生的语文成绩:", i + 1);
            scanf("%f", &stu[i].Chinese);
            printf("请输入第%d个学生的数学成绩:", i + 1);
            scanf("%f", &stu[i].Math);
            printf("请输入第%d个学生的英语成绩:", i + 1);
            scanf("%f", &stu[i].English);
            stu[i].Total = stu[i].Chinese + stu[i].Math + stu[i].English;
            stu[i].Ave = stu[i].Total / 3;
            cArr[i] = stu[i].Chinese;
            mArr[i] = stu[i].Math;
            eArr[i] = stu[i].English;
        }
        printf("各科成绩情况如下:");
        printf("\n语文最高分:%.2d\n", SubMax(cArr, num));
        printf("语文平均分:%.2f\n", SubAve(cArr, num));
        printf("\n数学最高分:%.2d\n", SubMax(mArr, num));
        printf("数学平均分:%.2f\n", SubAve(mArr, num));
        printf("\n英语最高分:%.2d\n", SubMax(eArr, num));
        printf("英语平均分:%.2f\n", SubAve(eArr, num));
}

// 输出每名学生的各科考试成绩和个人平均分
void Show()
{
    int i;
    // 输出成绩单表头
    printf("\n成绩单:\n");
    printf("姓名\t语文\t数学\t英语\t总成绩\t平均分\n");
    for (i = 0; i < num; i++)
        {
            // 使用格式化输出
            printf("%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", stu[i].Name, stu[i].Chinese, stu[i].Math, stu[i].English, stu[i].Total, stu[i].Ave);
        }
}


// 总分排序
void Sort()
{
    int i, j;
    for (i = 0; i < num - 1; i++)
        {
            for (j = 0; j < num - i - 1; j++)
                {
                    if (stu[j].Total < stu[j + 1].Total)
                        {
                            struct Student temp = stu[j];
                            stu[j] = stu[j + 1];
                            stu[j + 1] = temp;
                        }
                }
        }
    
    // 输出排序后的学生信息
    printf("\n学生总成绩排行:\n");
    printf("排名\t姓名\t总成绩\n");
    for (i = 0; i < num; i++)
        {
            printf("%d\t%s\t%.2f\n", i + 1, stu[i].Name, stu[i].Total);
        }
}


// 计算某一科目的最高分
int SubMax(int Arr[], int num)
{
        int max = Arr[0]; // 定义变量max，用来存储最高分
        int i;
        // 循环遍历数组，找到最高分
        for (i = 1; i < num; i++)
        {
            if (Arr[i] > max)
            {
                max = Arr[i];
            }
        }
        return max; // 返回最高分
}

// 计算某一科目的平均分
float SubAve(int Arr[], int num)
{
        int sum = 0; // 定义变量sum，用来存储总分
        int i;
        // 循环遍历数组，计算总分
        for (i = 0; i < num; i++)
        {
            sum += Arr[i];
        }
        return (float)sum / num; // 返回平均分
}