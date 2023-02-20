#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义学生信息的结构体
struct Student
{
    char Name[10]; // 姓名
    float Chinese; // 语文成绩
    float Math;    // 数学成绩
    float English; // 英语成绩
    float Total;   // 总分
    float Ave;     // 平均分
};

// 定义链表节点的结构体
typedef struct Node
{
    struct Student st;  // 数据域，存储学生信息
    struct node *pnext; // 指针域，指向下一个节点
} node, *pnode;         // 定义两个别名，方便后面使用

// 输入学生信息函数
pnode Input();

// 显示学生信息函数
void Show(pnode phead);

// 按总分排序函数
void Sort(pnode phead);

// 统计某一科目的最高分和平均分
void ASort(pnode phead);

int SubMax(int Arr[], int num);

float SubAve(int Arr[], int num);

int num; // 学生人数

int main()
{
    printf("欢迎来到期末成绩管理系统\n\n");
    int Item; // 保存操作命令

    pnode phead = NULL; // 定义一个指针
    phead = Input();    // 调用输入函数，输入每名学生的信息

    printf("\n每名学生的各科考试成绩和个人平均分:\n");
    Show(phead); // 调用显示函数，显示每名学生的信息

    Sort(phead); // 调用排序函数，按总分排序

    printf("\n学生总成绩排行:\n");
    Show(phead); // 调用显示函数，显示排序后的学生信息

    return 0;
}
// 输入学生信息函数
pnode Input()
{
    node stu; // 定义学生信息结构体

    // 分配内存给头节点
    pnode phead = (pnode)malloc(sizeof(node));
    // 判断内存是否分配成功
    if (NULL == phead)
    {
        printf("内存分配失败，程序终止!\n");
        exit(-1);
    }

    pnode ptail = phead; // 定义一个指向头节点的指针
    ptail->pnext = NULL; // 清空指针域

    printf("请输入学生的人数:");
    scanf("%d", &num); // 输入学生人数

    int i;                               // 循环变量
    int cArr[num], eArr[num], mArr[num]; // 定义存储每科成绩的数组

    for (i = 0; i < num; i++)
    {
        printf("请输入第%d个学生的姓名:", i + 1);
        scanf("%s", stu.st.Name); // 输入学生姓名

        printf("请输入第%d个学生的语文成绩:", i + 1);
        scanf("%f", &stu.st.Chinese); // 输入学生语文成绩
        cArr[i] = stu.st.Chinese;     // 将语文成绩存入数组

        printf("请输入第%d个学生的数学成绩:", i + 1);
        scanf("%f", &stu.st.Math); // 输入学生数学成绩
        mArr[i] = stu.st.Math;     // 将数学成绩存入数组

        printf("请输入第%d个学生的英语成绩:", i + 1);
        scanf("%f", &stu.st.English); // 输入学生英语成绩
        eArr[i] = stu.st.English;     // 将英语成绩存入数组

        stu.st.Total = stu.st.Chinese + stu.st.Math + stu.st.English; // 计算学生总分
        stu.st.Ave = stu.st.Total / 3;                                // 计算学生平均分

        // 将学生信息存入链表中
        ptail->pnext = (struct node*)malloc(sizeof(node));
        ptail = ptail->pnext;
        ptail->st = stu.st;
        ptail->pnext = NULL;
    }

    // 统计某一科目的最高分和平均分
    ASort(phead);

    return phead; // 返回头节点的指针
}

// 显示学生信息函数
void Show(pnode phead)
{
    pnode p = phead->pnext; // 定义一个指针，指向头节点的下一个节点
    // 循环遍历链表
    while (p != NULL)
    {
        // 输出学生信息
        printf("姓名:%s 语文:%.1f 数学:%.1f 英语:%.1f 总分:%.1f 平均分:%.1f\n",
               p->st.Name, p->st.Chinese, p->st.Math, p->st.English, p->st.Total, p->st.Ave);
        p = p->pnext; // 移动指针
    }
}

// 按总分排序函数
void Sort(pnode phead)
{
    pnode p, q;       // 定义两个指针，用来遍历链表
    p = phead->pnext; // 指针p指向头节点的下一个节点

    // 外层循环，从第一个节点开始遍历
    while (p != NULL)
    {
        q = p->pnext; // 指针q指向p的下一个节点

        // 内层循环，从p的下一个节点开始遍历
        while (q != NULL)
        {
            // 比较两个节点的总分，如果p的总分大于q的总分，就交换两个节点的信息
            if (p->st.Total > q->st.Total)
            {
                struct Student temp = p->st; // 定义一个临时结构体，用来交换两个节点的信息
                p->st = q->st;
                q->st = temp;
            }
            q = q->pnext; // 移动指针q
        }
        p = p->pnext; // 移动指针p
    }
}

// 统计某一科目的最高分和平均分
void ASort(pnode phead)
{
    int i;                               // 循环变量
    int cArr[num], eArr[num], mArr[num]; // 定义存储每科成绩的数组

    pnode p = phead->pnext; // 定义一个指针，指向头节点的下一个节点

    // 循环遍历链表，将每科成绩存入数组
    while (p != NULL)
    {
        cArr[i] = p->st.Chinese;
        mArr[i] = p->st.Math;
        eArr[i] = p->st.English;
        i++;
        p = p->pnext; // 移动指针
    }

    // 计算每科的最高分和平均分
    int cMax = SubMax(cArr, num);
    float cAve = SubAve(cArr, num);
    int mMax = SubMax(mArr, num);
    float mAve = SubAve(mArr, num);
    int eMax = SubMax(eArr, num);
    float eAve = SubAve(eArr, num);

    // 输出每科的最高分和平均分
    printf("语文最高分:%d 语文平均分:%.1f\n", cMax, cAve);
    printf("数学最高分:%d 数学平均分:%.1f\n", mMax, mAve);
    printf("英语最高分:%d 英语平均分:%.1f\n", eMax, eAve);
}

// 计算某一科目的最高分
int SubMax(int Arr[], int num)
{
    int i;            // 循环变量
    int Max = Arr[0]; // 定义最高分变量，初始值为数组第一个元素
    // 循环遍历数组，比较每一个元素的值
    for (i = 1; i < num; i++)
    {
        if (Max < Arr[i])
        {
            Max = Arr[i]; // 更新最高分
        }
    }

    return Max; // 返回最高分
}

// 计算某一科目的平均分
float SubAve(int Arr[], int num)
{
    int i;           // 循环变量
    float total = 0; // 定义一个变量，用来计算总分
    // 循环遍历数组，计算总分
    for (i = 0; i < num; i++)
    {
        total += Arr[i];
    }

    return total / num; // 返回平均分
}
