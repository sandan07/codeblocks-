#include <stdio.h>
#include <stdlib.h>

int count = 0; //计数变量
int sex;
int i;
int main()
{
    for(i=0;i<5;i++)
    {
        printf("请输入年龄:");
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
    printf("你一共输错了%d次\n",count);

    return 0;
}
