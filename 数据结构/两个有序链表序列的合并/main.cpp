#include <stdio.h>
#include <stdlib.h>
//L1��L2�Ǹ����Ĵ�ͷ���ĵ�����
//˵������Ҫ����һ��P->Next = NULL




typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲������������NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Read()
{
    List P, rear, node;
    P = (List)malloc(sizeof(struct Node));//ͷ�ڵ�ĳ�ʼ��
    rear = P;
    int i,num = 0;
    scanf("%d", &i);
    while(i--)
    {
        scanf("%d", &num);
        //�����½ڵ�
        node = (List)malloc(sizeof(struct Node));
        node->Data = num;
        node->Next = NULL;
        rear->Next = node;
        rear = node;
    }
    return P;

}

void Print( List L )
{
    int flag = 0;

    if(!L)//��������ǿյ�
    {
        printf("NULL");
        return;
    }

    while( L )
    {
        if (!flag) //���������ʽ
        {
            flag = 1;
        }else
        {
            printf(" ");
        }
        printf("%d", L->Data);
        L = L->Next;
    }
    printf("\n");
}

List Merge( List L1, List L2 )
{
    List t1, t2, P, rear, t;
    P = (List)malloc(sizeof(struct Node));
    P->Next = NULL;
    rear = P;
    t1 = L1->Next; t2 = L2->Next;
    while(t1 && t2)
    {
        if(t1->Data >= t2->Data)
        {
            rear->Next = t2;
            rear = t2;
            t2 = t2->Next;//������һ��
        }else
        {
            rear->Next = t1;
            rear = t1;
            t1 = t1->Next;
        }
    }
    while(t1)
    {
        rear->Next = t1;
        rear = t1;
        t1 = t1->Next;
    }
    while(t2)
    {
        rear->Next = t2;
        rear = t2;
        t2 = t2->Next;
    }
    L1->Next = NULL;
    L2->Next = NULL;
    return P;
}
