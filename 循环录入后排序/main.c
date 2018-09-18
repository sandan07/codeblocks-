#include <stdio.h>
#include <stdlib.h>

int count = 5;
double powers[] = {42332,45771,40907,41234,40767};
double deletePower;
int deleteIndex = -1;//赋一个不可能出现的值方便判断
int i,j;
double insertPower;
double temp;//定义临时变量
int main()
{
    printf("请输入你要查找的战斗力：");
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
        printf("没有找到你要的战斗力");
        exit(0);
    }else
    {
        for(i = deleteIndex; i < count - 1;i++)
        {
            powers[i] = powers[i+1];
        }
        count--;
    }
    printf("删除后的结果是：");
    for(i = 0; i < count; i++)
    {
        printf("%.2lf\t",powers[i]);
    }


    printf("请输入新的战力值：");
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
    printf("排序后的数组是：");
    for(i = 0; i < count;i++)
    {
        printf("%.0lf\t",powers[i]);
    }
    return 0;
}
