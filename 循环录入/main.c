#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sex;
    int count = 0;
    for(;;)
    {
        printf("�������Ա�:");
        scanf("%c",&sex);
        fflush(stdin);
        if (sex != 'm' && sex != 'M' && sex != 'F' && sex != 'f')
        {
            break;
        }
        else
        {
            count++;
        }
    }
    printf("��ȷ������%d��",count);
    return 0;
}
