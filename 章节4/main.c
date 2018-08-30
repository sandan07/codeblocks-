#include <stdio.h>

//打印简易加法表

int i = 0;
int n = 0;
int s = 0;

int main()
{
    printf("请输入你想得到的数字\n");
    scanf("%d",&n);
    printf("加法表:\n");
    for(i = 0;i < n;i++)
    {
        if(i % 2 == 0)
        {
            printf("%d + %d = %d\t",i,n-i,n);
        }
        else
        {
            printf("%d + %d = %d\n",i,n-i,n);
        };
    };
}
