#include<stdio.h>
int main()
{
    int MaxSum = -1;    //����������кͣ���һ�������ܵĳ�ֵ���������ж�ȫ�Ǹ��������
    int N;              //���г���
    int i;              //ѭ������
    int ThisSum = 0;    //����һ���ۼӱ���Ҫ����ֵΪ0
    scanf("%d", &N);    //��ȡ���鳤��
    int A[N];           //����һ������
    for( i = 0; i < N;i++)  //��ȡ����Ԫ��
    {
      scanf("%d", &A[i]);
    };
    int fn = 0;         //���еĿ�ʼ�±�
    int ln = N - 1;     //��ʼ���еĽ����±�
    int mn = N - 1;     //������еĿ�ʼ�±�
    for( i = 0; i < N ; i++)
    {
        ThisSum += A[i];
        if (ThisSum > MaxSum)
        {
            MaxSum = ThisSum;
            mn = fn;//���������и�����������еĿ�ʼ�±���³��ۼӱ���Ϊ0�����һ���±�
            ln = i;//�ѵ�ǰ���±긳��������еĽ����±�
        }else if ( ThisSum < 0 )
        {
            ThisSum = 0;
            fn = i + 1;//����ۼ����Ǹ����������±긳����ʼ
        }
    }
    if (MaxSum < 0)
    {
        printf("%d %d %d", 0, A[0], A[N - 1]);
    }else
    {
        printf("%d %d %d", MaxSum, A[mn], A[ln]);
    }

    return 0;
}
