#include<stdio.h>
#include<stdlib.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
//������
//�þ�̬�����ʾ��

struct TreeNode
{
    ElementType element;
    Tree left;
    Tree right;
}T1[MaxTree], T2[MaxTree];

int check[MaxTree];

Tree BuildTree(struct TreeNode T[]);
int Isomorphic(Tree R1, Tree R2);

int main()
{
    int R1,R2;
    //����1->����2->�Ƚ��Ƿ�ͬ���������
    R1 = BuildTree(T1);
    R2 = BuildTree(T2);
    if(Isomorphic(R1, R2)) printf("Yes\n");
    else printf("No\n");
    return 0;
}

Tree BuildTree(struct TreeNode T[])
{
    int N , root = -1, i;
    char cl, cr;
    scanf("%d\n", &N);
    if(N)
    {
        for( i = 0; i < N ; i++) check[i] = 0;
        for( i = 0; i < N ; i++)
        {
            scanf("%c %c %c\n", &T[i].element, &cl, &cr); // �����ַ� \n�������ջ��з���
            if(cl != '-')
            {
                T[i].left = cl - '0';   // -��0�� ���ǰ��ַ��͵�����ת����int�͵�
                check[T[i].left] = 1;   //�Ѽ��ڵ��Ϊ1
            }else T[i].left = Null;
            if(cr != '-')
            {
                T[i].right = cr - '0';
                check[T[i].right] = 1;
            }else T[i].right = Null;
        }
        for( i = 0; i < N; i++)
            if(!check[i]) break;    //�ҵ����ڵ㲻Ϊ1 �ľ��Ǹ��ڵ�
        root = i;
    }
    return root;
}

int Isomorphic(Tree R1, Tree R2)    //�ж����Ƿ�ͬ��
{
    //�������ǿգ�һ��Ϊ�գ����ڵ㲻ͬ������б����������ȫ��ͬ�������෴
    if((R1 == Null) && (R2 == Null)) return 1;
    if(((R1 == Null)&&(R2!=Null)) || ((R1 != Null) && (R2 == Null))) return 0;
    if(T1[R1].element != T2[R2].element) return 0;
    if((T1[R1].left == Null) && (T2[R2].left == Null)) return Isomorphic(T1[R1].right,T2[R2].right);
    if((T1[R1].left != Null && T2[R2].left != Null) && (T1[ T1[R1].left ].element == T2[ T2[R2].left ].element))//�����������ǿգ�������������ֵ��һ��
		return ( Isomorphic( T1[R1].left, T2[R2].left ) && Isomorphic( T1[R1].right, T2[R2].right ) );
	else
		return ( Isomorphic( T1[R1].left, T2[R2].right ) && Isomorphic( T1[R1].right, T2[R2].left ) );

}
