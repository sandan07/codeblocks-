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
//递归实现
/*  先序遍历
    1.访问根节点
    2.先序遍历其左子树
    2.线序遍历其右子树*/

//采用递归调用

void PreOrderTraversal( Bintree BT )
{
    if( BT ) printf("%d", BT->data);      //访问根节点
    PreOrderTraversal( BT->Left );        //访问左子树（也是根->左->右）的顺序
    PreOrderTraversal( BT->Right );       //访问右子树
}

/*中序遍历
    左->根->右
*/

void InOrderTraversal( Bintree BT )
{
    if( BT )
    {
        InOrderTraversal( BT->Left );       //去到了左边最底层
        printf("%d", BT->data );            //上级的根
        InOrderTraversal( BT->Right );      //去右边的最底层
    }
}


/*后序遍历
    左->右->根
*/

void PostOrderTraversal( Bintree BT )
{
    if ( BT )
    {
        PostOrderTraversal( BT->Left );       //去左边最底层 左边结束
        PostOrderTraversal( BT->Right );      //去右边 右边结束
        printf("%d", BT->data );              //打印根节点
    }
}

//先序、中序、后序的路径是一样的，但是访问个节点的时机不一样
//先序就是第一次碰到节点的时候就打印它，中序是第二次，后序是第三次。


//非递归实现，采用堆栈

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

//层序遍历 利用队列存储子节点 使得二叉树线性化

void LevelorderTraversal ( Bintree BT )
{
    Queue Q;
    Bintree T;

    if ( !BT ) return; /* 若是空树则直接返回 */

    Q = CreatQueue(); /* 创建空队列Q */
    AddQ( Q, BT );
    while ( !IsEmpty(Q) ) {
        T = DeleteQ( Q );
        printf("%d ", T->data); /* 访问取出队列的结点 */
        if ( T->Left )   AddQ( Q, T->Left );
        if ( T->Right )  AddQ( Q, T->Right );
    }
}

