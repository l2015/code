#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//学生结构体
struct Student
{
    char Name[10];
    float Chinese;
    float Math;
    float English;
    float Total;
    float Ave;
};
//结点
typedef struct Node
{
    struct Student st;  //数据域
    struct node *pnext; //指针域
} node, *pnode;         //*node等价于struct Student st,pnode等价于struct Node *pNext

//函数
pnode Input();          //输入学生成绩
void Show(pnode phead); //输出每名学生的各科考试成绩和个人平均分
void Sort(pnode phead); //总分排序
void ASort(pnode phead);
int num;
int SubMax(int Arr[], int num);
float SubAve(int Arr[], int num);

int main()
{
    printf("欢迎来到期末成绩管理系统\n\n");
    int Item;           //保存操作命令
    pnode phead = NULL; //定义一个指针
    phead = Input();
    printf("\n每名学生的各科考试成绩和个人平均分:\n");
    Show(phead);
    Sort(phead);
    printf("\n学生总成绩排行:\n");
    Show(phead);
    return 0;
}
//输入学生成绩
pnode Input()
{
    //  int num;                                   //学生的人数
    node stu;                                  //学生结构
    pnode phead = (pnode)malloc(sizeof(node)); //定义一个头结点并且为头结点分配内存
    //判断内存是否为空
    if (NULL == phead)
    {
        printf("内存分配失败,程序终止!\n");
        exit(-1);
    }
    pnode ptail = phead; //定义一个指向头结点的指针
    ptail->pnext = NULL; //清空指针域
    printf("请输入学生的人数:");
    scanf("%d", &num);
    int i;
    int cArr[num], eArr[num], mArr[num];
    for (i = 0; i < num; i++)
    {
        printf("请输入第%d个学生的姓名:", i + 1);
        scanf("%s", stu.st.Name);
        printf("请输入第%d个学生的语文成绩:", i + 1);
        scanf("%f", &stu.st.Chinese);
        printf("请输入第%d个学生的数学成绩:", i + 1);
        scanf("%f", &stu.st.Math);
        printf("请输入第%d个学生的英语成绩:", i + 1);
        scanf("%f", &stu.st.English);
        stu.st.Total = stu.st.Chinese + stu.st.Math + stu.st.English; //计算总分
        stu.st.Ave = stu.st.Total / 3.0f;                             //计算平均分
        pnode pnew = (pnode)malloc(sizeof(node));                     //为新节点分配内存
        //判断内存是否为空
        if (NULL == pnew)
        {
            printf("内存分配失败,程序终止!\n");
            exit(-1);
        }
        pnew->st = stu.st;   //初始化结点的数据域
        ptail->pnext = pnew; //将新结点挂到老结点后
        pnew->pnext = NULL;  //清空新结点的指针域
        ptail = pnew;        //将ptail移到新结点上

        cArr[i] = stu.st.Chinese;
        mArr[i] = stu.st.Math;
        eArr[i] = stu.st.English;
    }
    printf("\n\n全班学生各科成绩情况如下:\n");
    printf("语文最高成绩是：%d,平均成绩：%5.2f\n", SubMax(cArr, num), SubAve(cArr, num));
    printf("数学最高成绩是：%d,平均成绩：%5.2f\n", SubMax(mArr, num), SubAve(mArr, num));
    printf("英语最高成绩是：%d,平均成绩：%5.2f\n", SubMax(eArr, num), SubAve(eArr, num));
    return phead;
}
//计算最大成绩
int SubMax(int Arr[], int num)
{

    int i, max;
    max = Arr[0];
    for (i = 0; i < num; i++)
    {
        if (max < Arr[i])
        {
            max = Arr[i];
        }
    }
    return max;
}
//计算平均成绩
float SubAve(int Arr[], int num)
{

    float sum = 0;

    for (int i = 0; i < num; i++)
    {
        sum = sum + Arr[i];
    }

    return sum / num;
}

//输出每名学生的各科考试成绩和个人平均分
void Show(pnode phead)
{
    //定义一个指针用于遍历学生信息
    pnode p = phead->pnext;
    printf("姓名 语文 数学  英语 总分 平均分\n");
    while (NULL != p)
    {
        printf("%s    %g    %g    %g   %g    %g\n", p->st.Name, p->st.Chinese, p->st.Math, p->st.English, p->st.Total, p->st.Ave);
        p = p->pnext;
    }
}
//总分排序
void Sort(pnode phead)
{
    pnode p, q; //定义两个指针
    node temp;
    for (p = phead->pnext; NULL != p; p = p->pnext)
    {
        for (q = p->pnext; NULL != q; q = q->pnext)
        {
            if (p->st.Total < q->st.Total) //当前一个学生的总分小于后一个学生的总分时
            {
                temp.st = p->st; //交换学生的位置
                p->st = q->st;
                q->st = temp.st;
            }
        }
    }
}
