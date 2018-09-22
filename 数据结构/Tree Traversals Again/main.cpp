#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef NULL
#define NULL 0
#endif // NULL
typedef int ElementType;

struct TNode
{
    ElementType Data;
    struct TNode *Left;
    struct TNode *Right;
};
typedef struct TNode *BinTree;
typedef BinTree PtrToTNode;

struct SNode
{
    ElementType Data;
    struct SNode *Next;
};
typedef struct SNode *Stack;

BinTree BuildTree(int *pre, int *in, int N);
BinTree CreateTNode();
Stack CreateStack();
void push(Stack s,ElementType e);
ElementType pop(Stack s);
void PostOrderTraversal(BinTree BT, ElementType root);

int main()
{
    BinTree BT;
    Stack S;
    int N,i,in_index,pre_index,e;
    char action[5];

    S = CreateStack();

    scanf("%d",&N);
    getchar();

    int in[N],pre[N];
    in_index = pre_index = 0;
    for(i=0;i<2*N;i++)
    {
        scanf("%s",action);
        if(strcmp(action,"Push")==0)
        {
            scanf("%d",&e);
            pre[pre_index++] = e;
            push(S,e);
        }
        else
        {
            in[in_index++] = pop(S);
        }
    }
    BT = BuildTree(pre,in,N);
    PostOrderTraversal(BT,BT->Data);
    return 0;
}

BinTree BuildTree(int *pre, int *in, int N)
{
    BinTree BT;
    ElementType root;
    int LeftNum, RightNum, flag, i;
    int Left_pre[N], Right_pre[N], Left_in[N], Right_in[N];
    if(N==1)
    {
        BT = CreateTNode();
        BT->Data = pre[0];
        BT->Left = NULL;
        BT->Right = NULL;
        return BT;
    }
    else if(N == 0)
        return NULL;
    else{
        root = pre[0];
        BT = CreateTNode();
        BT->Data = root;
        flag = LeftNum = RightNum = 0;
        for(i=0;i<N;i++)
        {
            if(in[i]!=root)
            {
                if(flag)
                {
                    Right_in[RightNum++] = in[i];
                }
                else
                {
                    Left_in[LeftNum++] = in[i];
                }
            }
            else
            {
                flag = 1;
            }
        }
        for(i=0;i<LeftNum;i++)
            Left_pre[i] = pre[i+1];
        for(i=0;i<RightNum;i++)
            Right_pre[i] = pre[LeftNum+i+1];
        BT->Left = BuildTree(Left_pre,Left_in,LeftNum);
        BT->Right = BuildTree(Right_pre,Right_in,RightNum);
        return BT;
    }
}
BinTree CreateTNode()
{
    BinTree BT;
    BT = (BinTree)malloc(sizeof(struct TNode));
    BT->Left = NULL;
    BT->Right = NULL;
    BT->Data = 0;
    return BT;
}

Stack CreateStack()
{
    Stack s;
    s = (Stack)malloc(sizeof(struct SNode));
    s->Next = NULL;
    return s;
}
void push(Stack s,ElementType e)
{
    if(s == NULL)
        s = CreateStack();
    Stack PtrToSNode;
    PtrToSNode = (Stack)malloc(sizeof(struct SNode));
    PtrToSNode->Data = e;
    PtrToSNode->Next = s->Next;
    s->Next = PtrToSNode;
    return;
}
ElementType pop(Stack s)
{
    Stack tmp;
    ElementType data;
    if(s == NULL || s->Next == NULL){
        printf("stack empty!\n");
        return NULL;
    }
    tmp = s->Next;
    s->Next = tmp->Next;
    data = tmp->Data;
    free(tmp);
    return data;
}

void PostOrderTraversal(BinTree BT,ElementType root)
{
    if(BT->Left)
        PostOrderTraversal(BT->Left,root);
    if(BT->Right)
        PostOrderTraversal(BT->Right,root);
    if(BT->Data == root)
        printf("%d",BT->Data);
    else
        printf("%d ",BT->Data);
}
