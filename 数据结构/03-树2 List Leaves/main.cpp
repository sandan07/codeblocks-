#include <stdio.h>
#include <stdlib.h>
#ifndef NULL
#define NULL 0
#endif // NULL
#define MAXSIZE 10
#define Null -1

typedef int ElementType;
struct QNode
{
    ElementType Data;
    struct QNode *Next;
};
typedef struct QNode *Position;
typedef Position Queque;

struct TNode
{
    ElementType Data;
    int left;
    int right;
} T[MAXSIZE];

Queque CreateQueue();
int add(Queque q, ElementType e);
ElementType Delete(Queque q);
int IsEmpty(Queque q);
int BuildTree();
void LevelOrderTraversal(int root);

int main()
{
    int root;
    root = BuildTree();
    LevelOrderTraversal(root);
    return 0;
}


/*队列抽象数据结构*/
Queque CreateQueue()
{
    Queque q;
    q = (Queque)malloc(sizeof(struct QNode));
    q->Data = 0;
    q->Next = NULL;
    return q;
}

int add(Queque q, ElementType e)
{
    Position p,tmp;
    if(!q)
        q = CreateQueue();
    tmp = q;
    while(tmp->Next)
    tmp = tmp->Next;
    p = (Position)malloc(sizeof(struct QNode));
    p->Data = e;
    p->Next = NULL;
    tmp->Next = p;
    return 0;
}

ElementType Delete(Queque q)
{
    ElementType First;
    Position tmp;
    if(!q || q->Next == NULL)
        return NULL;
    else
    {
        tmp = q->Next;
        q->Next = tmp->Next;
        First = tmp->Data;
        free(tmp);
        return First;
    }
}
int IsEmpty(Queque q)
{
    return(q->Next == NULL);
}

/*二叉树静态链表数据结构*/

int BuildTree()
{
    int N;
    scanf("%d",&N);
    getchar();
    if(N)
    {
        int i,root;
        int check[N];
        char cl,cr;
        for(i=0;i<N;i++)
            check[i] = 0;
        for(i=0;i<N;i++)
        {
            scanf("%c %c",&cl,&cr);
            getchar();
            if(cl!='-')
            {
                T[i].left = cl-'0';
                check[T[i].left] = 1;
            }
            else
                T[i].left = Null;
            if(cr!='-')
            {
                T[i].right = cr-'0';
                check[T[i].right] = 1;
            }
            else
                T[i].right = Null;
        }
        for(i=0;i<N;i++)
        {
            if(check[i]==0){
                root = i;
                break;
            }
        }
        return root;
    }
    else
        return Null;
}

void LevelOrderTraversal(int root)
{
    Queque q;
    q = CreateQueue();
    if(root<0)
        return;
    int tmp,flag = 1;
    add(q,root);
    while(!IsEmpty(q))
    {
        tmp = Delete(q);
        if(T[tmp].left == Null && T[tmp].right == Null)
        {
            if(flag)
            {
                printf("%d",tmp);
                flag = 0;
            }
            else
                printf(" %d",tmp);
        }
        else if(T[tmp].left == Null)
            add(q,T[tmp].right);
        else if(T[tmp].right == Null)
            add(q,T[tmp].left);
        else
        {
            add(q,T[tmp].left);
            add(q,T[tmp].right);
        }
    }
}
