#include <stdio.h>
#include <stdlib.h>
int score[7]={8,4,2,1,23,344,12};
int main()
{
    int i;
    int sum = 0;
    int avg = 0;
    int searchNum;
    for(i = 0; i < 7 ; i++)
    {
        printf("%d,",score[i]);
    }
    printf("\n");
    for(i = 0;i < 7; i++)
    {
        sum += score[i];
    }
    avg= sum / 7.0;
    printf("%d,%d\n",sum,avg);
    printf("��������Ҫ���ҵ����֣�");
    scanf("%d",&searchNum);
    for(i = 0;i < 7; i++)
    {
        if(searchNum == score[i])
        {
            printf("���ҵ���ƥ������֣�%d\n",score[i]);
            break;
        }
    }
    if(i == 7)
    {
        printf("û���ҵ���Ҫ������\n");//�����˳��������i��7��������������ѭ������û���ҵ���ͬ������
    }


    return 0;
}
