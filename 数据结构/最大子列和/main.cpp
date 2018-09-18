#include<stdio.h>
int main()
{
    int MaxSum = -1;    //定义最大子列和，给一个不可能的初值让他可以判断全是负数的情况
    int N;              //数列长度
    int i;              //循环变量
    int ThisSum = 0;    //定义一个累加变量要给初值为0
    scanf("%d", &N);    //获取数组长度
    int A[N];           //定义一个数组
    for( i = 0; i < N;i++)  //获取数组元素
    {
      scanf("%d", &A[i]);
    };
    int fn = 0;         //子列的开始下标
    int ln = N - 1;     //初始子列的结束下标
    int mn = N - 1;     //最大子列的开始下标
    for( i = 0; i < N ; i++)
    {
        ThisSum += A[i];
        if (ThisSum > MaxSum)
        {
            MaxSum = ThisSum;
            mn = fn;//如果最大子列更新则将最大子列的开始下标更新成累加变量为0后面的一个下标
            ln = i;//把当前的下标赋给最大子列的结束下标
        }else if ( ThisSum < 0 )
        {
            ThisSum = 0;
            fn = i + 1;//如果累加器是负数则把这个下标赋给开始
        }
    }
    if (MaxSum < 0)
    {
        printf("%d %d %d", 0, A[0], A[N - 1]);
    }else
    {
        printf("%d %d %d", MaxSum, A[mn], A[ln]);
    }

    return 0;
}
