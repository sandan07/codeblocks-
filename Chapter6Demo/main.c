#include <stdio.h>
#include <stdlib.h>
#define N 5
int main()
{
    //��̬¼��
    double score[N];
    int i;
    for(i = 0;i < N;i++)
    {
        printf("�������%dλͬѧ�ĳɼ���",i + 1);
        scanf("%lf",&score[i]);
    }
    for(i = 0;i < N;i++)
    {
        printf("��%dλͬѧ�ĳɼ���%.0lf\n",i+1,score[i]);
    }
    return 0;
}
