#include <stdio.h>

//��ӡ���׼ӷ���

int i = 0;
int n = 0;
int s = 0;

int main()
{
    printf("����������õ�������\n");
    scanf("%d",&n);
    printf("�ӷ���:\n");
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
