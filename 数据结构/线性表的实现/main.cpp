#include<stdio.h>
#include<stdlib.h>
#define Maxsize 10000
typedef struct LNode *List;

struct LNode{
    int Data[Maxsize];
    int Last;
};

struct LNode L;
List PtrL;

//初始化
List MakeEmpty()
{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL-> Last = -1;
    return PtrL;
}
//查找
int Find(int X, List PtrL)
{
    int i = 0;
    while( i <= PtrL->Last && PtrL->Data[i]!= X)
    {
        i++;
        if (i > PtrL->Last) return -1;//如果没找到返回的是-1
        else return i;//找到了就返回存储位置
    }
}
//插入
//把i的位置以后的先全部移动一位
//然后插入i
void insert(int X, int i , List PtrL)
{
    int j;
    //首先判断表有没有满
    if (PtrL->Last == Maxsize - 1)
    {
        printf("Full");
        return;
    }
    //然后判断插入的位置是不是合适，在第0位以前或者最后一位往后
    if(i < 1 || i > PtrL->Last+2)
    {
        printf("插入位置不合法");
        return;
    }
    for (j = PtrL->Last; j >= i - 1; j--)
        PtrL->Data[j+1] = PtrL->Data[j];//移动i-1以后的位置
        PtrL->Data[i-1] = X;
        PtrL->Last++;//表的长度加一
        return;
}

//删除 和插入方法相反

void Delete(int i, List PtrL)
{
    int j;//临时变量
    if(i < 1 ||i > PtrL->Last + 1)
    {
        printf("不存在第%d个元素\n", i);
        return;
    }
    for(j = i; j < PtrL->Last; j++)
    {
        PtrL->Data[j-1] = PtrL->Data[j];
    }
    PtrL->Last--;//表的长度减一
    return;
}
