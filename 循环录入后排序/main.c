#include <stdio.h>
#include <stdlib.h>

int count = 5;
double powers[] = {42332,45771,40907,41234,40767};
double deletePower;
int deleteIndex = -1;//��һ�������ܳ��ֵ�ֵ�����ж�
int i,j;
double insertPower;
double temp;//������ʱ����
int main()
{
    printf("��������Ҫ���ҵ�ս������");
    scanf("%lf",&deletePower);
    for(i = 0; i < count; i++)
    {
        if(deletePower == powers[i])
        {
            deleteIndex = i;
            break;
        }
    }
    if(-1 == deleteIndex)
    {
        printf("û���ҵ���Ҫ��ս����");
        exit(0);
    }else
    {
        for(i = deleteIndex; i < count - 1;i++)
        {
            powers[i] = powers[i+1];
        }
        count--;
    }
    printf("ɾ����Ľ���ǣ�");
    for(i = 0; i < count; i++)
    {
        printf("%.2lf\t",powers[i]);
    }


    printf("�������µ�ս��ֵ��");
    scanf("%lf",&insertPower);
    powers[count] = insertPower;
    count++;

    for(i = 0; i < count - 1; i++)
    {
        for(j = 0; j < count - i - 1; j++)
        {
            if(powers[j] < powers[j+1])
               {
                   temp = powers[j];
                   powers[j] = powers[j+1];
                   powers[j+1] = temp;
                }
        }
    }
    printf("�����������ǣ�");
    for(i = 0; i < count;i++)
    {
        printf("%.0lf\t",powers[i]);
    }
    return 0;
}
