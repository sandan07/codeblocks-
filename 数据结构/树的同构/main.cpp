#include<stdio.h>
#include<stdlib.h>

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
//创建树
//用静态链表表示树

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
    //建树1->建树2->比较是否同构并且输出
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
            scanf("%c %c %c\n", &T[i].element, &cl, &cr); // 接受字符 \n代表吸收换行符等
            if(cl != '-')
            {
                T[i].left = cl - '0';   // -‘0’ 就是把字符型的数字转换成int型的
                check[T[i].left] = 1;   //把检查节点标为1
            }else T[i].left = Null;
            if(cr != '-')
            {
                T[i].right = cr - '0';
                check[T[i].right] = 1;
            }else T[i].right = Null;
        }
        for( i = 0; i < N; i++)
            if(!check[i]) break;    //找到检查节点不为1 的就是根节点
        root = i;
    }
    return root;
}

int Isomorphic(Tree R1, Tree R2)    //判断树是否同构
{
    //两个都是空，一个为空，根节点不同，都是斜二叉树，完全相同，正好相反
    if((R1 == Null) && (R2 == Null)) return 1;
    if(((R1 == Null)&&(R2!=Null)) || ((R1 != Null) && (R2 == Null))) return 0;
    if(T1[R1].element != T2[R2].element) return 0;
    if((T1[R1].left == Null) && (T2[R2].left == Null)) return Isomorphic(T1[R1].right,T2[R2].right);
    if((T1[R1].left != Null && T2[R2].left != Null) && (T1[ T1[R1].left ].element == T2[ T2[R2].left ].element))//左子树都不是空，而且左子树的值都一样
		return ( Isomorphic( T1[R1].left, T2[R2].left ) && Isomorphic( T1[R1].right, T2[R2].right ) );
	else
		return ( Isomorphic( T1[R1].left, T2[R2].right ) && Isomorphic( T1[R1].right, T2[R2].left ) );

}
