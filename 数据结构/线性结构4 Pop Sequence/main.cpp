#include<stdio.h>
#include<stdlib.h>
#define maxsize 10005

//ģ���ջ��ջ���̣�������ջ��ͬʱ���ջ���еĵ�һ��Ԫ�ضԱȣ�������򵯳�ջ��Ԫ�أ�����ȥ��ջ���е���Ԫ�أ�
//ȫ������ջ���ջ�����е�Ԫ��ȫ������ȥ�򷵻�1�����򷵻�0��

typedef struct Node* Stack;

struct Node
{
    int capacity;
    int top;
    int data[maxsize];
};

/*  1.����һ����ջ
    2.������ѹ���ջ
    3.����ϵ����ݺ�����Ա�
    4.�����ݵ�����ջ
    5.�ݻٶ�ջ
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
