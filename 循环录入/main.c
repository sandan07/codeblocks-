#include <stdio.h>
#include <stdlib.h>

int main()
{
    char sex;
    int count = 0;
    for(;;)
    {
        printf("请输入性别:");
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
    printf("正确输入了%d次",count);
    return 0;
}
