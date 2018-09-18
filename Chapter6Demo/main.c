#include <stdio.h>
#include <stdlib.h>
#define N 5
int main()
{
    //动态录入
    double score[N];
    int i;
    for(i = 0;i < N;i++)
    {
        printf("请输入第%d位同学的成绩：",i + 1);
        scanf("%lf",&score[i]);
    }
    for(i = 0;i < N;i++)
    {
        printf("第%d位同学的成绩是%.0lf\n",i+1,score[i]);
    }
    return 0;
}
