#include"Stack.h"
bool IsFull( Stack S )
{
    return (S->Top == S->MaxSize-1);
}

bool Push( Stack S, ElementType X )
{
    if ( IsFull(S) ) {
        printf("��ջ��");
        return false;
    }
    else {
        S->Data[++(S->Top)] = X;
        return true;
    }
}

bool IsEmpty( Stack S )
{
    return (S->Top == -1);
}

ElementType Pop( Stack S )
{
    if ( IsEmpty(S) ) {
        printf("��ջ��");
        return -1; /* ERROR��ElementType������ֵ����־���� */
    }
    else
        return ( S->Data[(S->Top)--] );
}
