#include<stdio.h>

int main()
{
    /*�����ʽ:������һ���и��������α߳� N��3��N��20������������αߵ�ĳ���ַ� C�����һ���ո�

    �����ʽ��
    ����ɸ����ַ� C �����������Ρ�����ע�⵽�м����м���
    ����Ϊ���ý������ȥ���������Σ��������������ʵ������������ 50%����������ȡ������
    */

    int N;
    char F;
    scanf("%d %c", &N, &F);//��ȡ�߳�
    if (N % 2 == 0)     //�߳���ż��
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
