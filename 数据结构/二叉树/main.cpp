#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
#include"Stack.h"
typedef struct TreeNode *Bintree;

struct TreeNode
{
    int data;
    Bintree Left;
    Bintree Right;
};
//�ݹ�ʵ��
/*  �������
    1.���ʸ��ڵ�
    2.���������������
    2.���������������*/

//���õݹ����

void PreOrderTraversal( Bintree BT )
{
    if( BT ) printf("%d", BT->data);      //���ʸ��ڵ�
    PreOrderTraversal( BT->Left );        //������������Ҳ�Ǹ�->��->�ң���˳��
    PreOrderTraversal( BT->Right );       //����������
}

/*�������
    ��->��->��
*/

void InOrderTraversal( Bintree BT )
{
    if( BT )
    {
        InOrderTraversal( BT->Left );       //ȥ���������ײ�
        printf("%d", BT->data );            //�ϼ��ĸ�
        InOrderTraversal( BT->Right );      //ȥ�ұߵ���ײ�
    }
}


/*�������
    ��->��->��
*/

void PostOrderTraversal( Bintree BT )
{
    if ( BT )
    {
        PostOrderTraversal( BT->Left );       //ȥ�����ײ� ��߽���
        PostOrderTraversal( BT->Right );      //ȥ�ұ� �ұ߽���
        printf("%d", BT->data );              //��ӡ���ڵ�
    }
}

//�������򡢺����·����һ���ģ����Ƿ��ʸ��ڵ��ʱ����һ��
//������ǵ�һ�������ڵ��ʱ��ʹ�ӡ���������ǵڶ��Σ������ǵ����Ρ�


//�ǵݹ�ʵ�֣����ö�ջ

//void InOrderTraversal( Bintree BT )
//{
//    Bintree T = BT;
//    Stack s = CreateStack( maxsize );
//    while(T || !IsEmpty(s))
//    {
//        while(T)
//        {
//            Push(s, T->data);
//            T = T->Left;
//        }
//        if(!IsEmpty(s))
//        {
//            T = Pop(s);
//            printf("%5d", T->data);
//            T = T->Right;
//        }
//    }

//������� ���ö��д洢�ӽڵ� ʹ�ö��������Ի�

void LevelorderTraversal ( Bintree BT )
{
    Queue Q;
    Bintree T;

    if ( !BT ) return; /* ���ǿ�����ֱ�ӷ��� */

    Q = CreatQueue(); /* �����ն���Q */
    AddQ( Q, BT );
    while ( !IsEmpty(Q) ) {
        T = DeleteQ( Q );
        printf("%d ", T->data); /* ����ȡ�����еĽ�� */
        if ( T->Left )   AddQ( Q, T->Left );
        if ( T->Right )  AddQ( Q, T->Right );
    }
}

