#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100002
struct Node
{
    int data;
    int next;
};

struct Node workArray[Maxsize];
int Input(struct Node array[]);
void ReverseList(struct Node array[], int *head, int k);
void PrintList(int head, struct Node array[]);
int count(int *head, struct Node array[]);
int k, head;

int main()
{
    head = Input(workArray);
    ReverseList(workArray, &head, k);
    PrintList(head, workArray);
    return 0;
}


int Input(struct Node array[])
{
    int inputlength, inputhead;
    int address, data, next;

    scanf("%d%d%d", &inputhead, &inputlength, &k);
    for(int i = 0; i < inputlength; i++)
    {
        scanf("%d%d%d", &address, &data, &next);
        array[address].data = data;
        array[address].next = next;
    }
    return inputhead;
}

void ReverseList(struct Node array[],int *head, int k)
{
    /*
    ������count�������ȣ��ŵ�cnt�б��档ÿ��ִ��cnt�������k�����cnt<k�򲻽��з�ת
    Ȼ��ʹ��ptr1 ptr2 ptr3 ����ָ��
    ptr1Ϊ��ǰ�ڵ� ptr2Ϊ��һ���ڵ� ��ptr1->ptr2��Ϊptr2->ptr1����Ϊptr2�е�nextԭ�����ݻᶪʧ������ptr3����ptr2����һ���ڵ�
    ִ����һ�κ�k���ڵ������ڣ�ͷβ������
    ��lastend����ǰһ�����ĩ�ˣ�����һ�����ͷ�ڵ�
    nexthead����һ�����ͷ��㣬ͬ��Ҳ�Ǹ����鷭ת����ĩ�ˡ�������ǰ��lastend=nexthead���档
    */
    int cnt;
    if(k == 1)
        return;
    cnt = count(*head, array);
    //ptr1ָ��ǰָ�룬ptr2ָ��һ��Ҫָ��ptr1�ģ�ptr3ָ��δ����ת����һ����
    int i,ptr1,ptr2,ptr3,firstflag=0,nexthead=*head,lastend=-2;
    while(cnt>=k)
    {
        ptr1 = nexthead;
        ptr2 = array[ptr1].next;
        for(i = 1; i < k; i++)
        {
            ptr3 = array[ptr2].next;
            array[ptr2].next = ptr1;
            ptr1 = ptr2;
            ptr2 = ptr3;
        }
        array[nexthead].next = ptr3;
        if(firstflag == 0)
        {
            lastend = nexthead;
            *head = ptr1;
        }
        else
        {
            array[lastend].next = ptr1;
            lastend = nexthead;
        }
        firstflag ++;
        nexthead = ptr2;
        cnt -= k;
    }
}

int count(int*head, struct Node array[])//��һ���б��м���Ԫ��
{
    int i, cnt = 1;
    i = head;
    while(array[i].next != -1)
    {
        cnt++;
        i = array[i].next;
    }
    return cnt;
}

void PrintList(int head,struct Node array[])
{
    int idx=head;
    while(array[idx].next!= -1){
        printf("%05d %d %05d\n",idx,array[idx].data,array[idx].next);
        idx=array[idx].next;
    }
    printf("%05d %d %d",idx,array[idx].data,array[idx].next);
}
