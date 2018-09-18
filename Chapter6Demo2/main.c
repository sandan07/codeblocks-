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
    printf("请输入需要查找的数字：");
    scanf("%d",&searchNum);
    for(i = 0;i < 7; i++)
    {
        if(searchNum == score[i])
        {
            printf("查找到了匹配的数字：%d\n",score[i]);
            break;
        }
    }
    if(i == 7)
    {
        printf("没有找到你要的数字\n");//正常退出的情况下i是7，代表着走完了循环但是没有找到相同的数字
    }


    return 0;
}
