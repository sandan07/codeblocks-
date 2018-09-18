#include<stdio.h>
#include<stdlib.h>
#define Maxsize 10000
typedef struct LNode *List;

struct LNode{
    int Data[Maxsize];
    int Last;
};

struct LNode L;
List PtrL;

//��ʼ��
List MakeEmpty()
{
    List PtrL;
    PtrL = (List)malloc(sizeof(struct LNode));
    PtrL-> Last = -1;
    return PtrL;
}
//����
int Find(int X, List PtrL)
{
    int i = 0;
    while( i <= PtrL->Last && PtrL->Data[i]!= X)
    {
        i++;
        if (i > PtrL->Last) return -1;//���û�ҵ����ص���-1
        else return i;//�ҵ��˾ͷ��ش洢λ��
    }
}
//����
//��i��λ���Ժ����ȫ���ƶ�һλ
//Ȼ�����i
void insert(int X, int i , List PtrL)
{
    int j;
    //�����жϱ���û����
    if (PtrL->Last == Maxsize - 1)
    {
        printf("Full");
        return;
    }
    //Ȼ���жϲ����λ���ǲ��Ǻ��ʣ��ڵ�0λ��ǰ�������һλ����
    if(i < 1 || i > PtrL->Last+2)
    {
        printf("����λ�ò��Ϸ�");
        return;
    }
    for (j = PtrL->Last; j >= i - 1; j--)
        PtrL->Data[j+1] = PtrL->Data[j];//�ƶ�i-1�Ժ��λ��
        PtrL->Data[i-1] = X;
        PtrL->Last++;//��ĳ��ȼ�һ
        return;
}

//ɾ�� �Ͳ��뷽���෴

void Delete(int i, List PtrL)
{
    int j;//��ʱ����
    if(i < 1 ||i > PtrL->Last + 1)
    {
        printf("�����ڵ�%d��Ԫ��\n", i);
        return;
    }
    for(j = i; j < PtrL->Last; j++)
    {
        PtrL->Data[j-1] = PtrL->Data[j];
    }
    PtrL->Last--;//��ĳ��ȼ�һ
    return;
}
