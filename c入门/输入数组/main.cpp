#include<stdio.h>

int main()
{
    const int number = 10;//�������鳤��
    int x;
    int count[number];
    int i;
    for (i = 0; i < number ; i++)//�����ʼ��
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
