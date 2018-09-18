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
    首先用count求链表长度，放到cnt中保存。每次执行cnt自身减掉k，如果cnt<k则不进行翻转
    然后使用ptr1 ptr2 ptr3 三个指针
    ptr1为当前节点 ptr2为下一个节点 将ptr1->ptr2改为ptr2->ptr1。因为ptr2中的next原有内容会丢失，故用ptr3保存ptr2的下一个节点
    执行完一次后，k个节点区间内，头尾互换。
    故lastend保存前一区块的末端，是上一区间的头节点
    nexthead即下一区块的头结点，同样也是该区块翻转完后的末端。于是提前用lastend=nexthead保存。
    */
    int cnt;
    if(k == 1)
        return;
    cnt = count(*head, array);
    //ptr1指当前指针，ptr2指下一个要指向ptr1的，ptr3指向还未做反转的下一个。
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

int count(int*head, struct Node array[])//数一下列表有几个元素
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
