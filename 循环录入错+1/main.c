#include <stdio.h>
#include <stdlib.h>

int count = 0; //��������
int sex;
int i;
int main()
{
    for(i=0;i<5;i++)
    {
        printf("����������:");
        scanf("%d",&sex);
        if (sex >= 0)
        {
            continue;
        }
        count++;

        /*if (sex > 0)
        {
            continue;
        }
        else
        {
            count++;
        }*/
    }
    printf("��һ�������%d��\n",count);

    return 0;
}
