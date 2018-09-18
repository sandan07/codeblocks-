#include<stdio.h>

int main()
{
    /*输入格式:输入在一行中给出正方形边长 N（3≤N≤20）和组成正方形边的某种字符 C，间隔一个空格。

    输出格式：
    输出由给定字符 C 画出的正方形。但是注意到行间距比列间距大，
    所以为了让结果看上去更像正方形，我们输出的行数实际上是列数的 50%（四舍五入取整）。
    */

    int N;
    char F;
    scanf("%d %c", &N, &F);//获取边长
    if (N % 2 == 0)     //边长是偶数
    {
        for (int i = 0; i < N / 2; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                if (i == 0 || i == (N/2)-1)
                {
                    printf("%c", F);
                }else
                {
                    if ( j == 0 || j == N-1)
                    {
                        printf("%c",F);
                    }else
                    {
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }
    }else
    {
        for (int i = 0; i < N / 2 + 1; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {
                if (i == 0 || i == (N/2 + 1)-1)
                {
                    printf("%c", F);
                }else
                {
                    if ( j == 0 || j == N-1)
                    {
                        printf("%c",F);
                    }else
                    {
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }
    }

    return 0;
}
