#include<stdio.h>
#include<stdlib.h>
#define maxsize 10005

//模拟进栈出栈过程：依次入栈并同时与出栈序列的第一个元素对比；若相等则弹出栈顶元素，并消去出栈序列的首元素；
//全部已入栈后出栈序列中的元素全部被消去则返回1，否则返回0；

typedef struct Node* Stack;

struct Node
{
    int capacity;
    int top;
    int data[maxsize];
};

/*  1.创建一个堆栈
    2.将数据压入堆栈
    3.将最顶上的数据和输入对比
    4.将数据弹出堆栈
    5.摧毁堆栈
*/

Stack CreateStack(int capacity);
int Push(Stack s, int x);
int Top(Stack s);
void Pop(Stack s);
void distory(Stack s);
int IsPopseq(int* popOrder, int capacity, int n);

int main()
{
    int m, n, k;
    scanf("%d%d%d", &m, &n, &k);
    int popOrder[1000];
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &popOrder[j]);
        }
        if(IsPopseq(popOrder, m, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

Stack CreateStack(int capacity)
{
    Stack s = (Stack)malloc(sizeof(struct Node));
    s->top = -1;
    s->capacity = capacity;
    return s;
}

int Push(Stack s, int x)
{
    if(s->capacity - s->top <=1)
        return 0;
    s->data[++s->top] = x;
    return 1;
}

int Top(Stack s)
{
    if(s->top >= 0)
		return s->data[s->top];
	else
		return -1;
}

void Pop(Stack s)
{
    s->top--;
}

void distory(Stack s)
{
    free(s);
}

int IsPopseq(int* popOrder, int capacity, int n)
{
    Stack s;
    s = CreateStack(capacity);
    int head = 0;
    for (int i =1; i<=n ; i++)
    {
        if(!Push(s,i))
        {
            distory(s);
            return 0;
        }
        while(Top(s) == popOrder[head])
        {
            Pop(s);
            head++;
        }
    }
    distory(s);
    if(head != n)
        return 0;
    return 1;
}
