#include<stdio.h>
#include<stdlib.h>
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node { /* �����еĽ�� */
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode {
    Position Front, Rear;  /* ���е�ͷ��βָ�� */
    int MaxSize;           /* ����������� */
};
typedef struct QNode *Queue;


