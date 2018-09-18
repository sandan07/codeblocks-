#include<stdio.h>

int main()
{
    const int number = 10;//定义数组长度
    int x;
    int count[number];
    int i;
    for (i = 0; i < number ; i++)//数组初始化
    {
        count[i] = 0;
    }
    scanf("%d", &x);
    while( x!=-1 )
    {
        if( x > 0 && x <= 9 )
        {
            count[x]++;
        }
        scanf("%d", &x);
    }
    for(i = 0; i < number; i++)
    {
        printf("%d.%d\t", i, count[i]);
    }
    return 0;
}
