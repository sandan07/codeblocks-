#include<stdio.h>

/*struct//定义一个结构体，把amount和name放在一起
{
    int amount;
    char *name;
}coins[] = {
    {1,"penny"},
    {5,"nickel"},
    {10,"dime"},
    {25,"quarter"},
    {50,"half-dollar"}
};*/
/*
int search{int key, int a[], int len}
{
    int ret = -1;
    for (int i = 0; i < len; i++)
        if( key == a[i] )
    {
        ret = i;
        break;
    }
    return ret;
}

*/

int biosearch(int key, int a[], int len)//二分搜索
{
    int ret = -1;
    int left = 0;
    int right = len - 1;
    while(right > left)
    {
        int mid = left + (right - left)/2
        if(a[mid] == k)
        {
            ret = mid;
            break;
        }else if(a[mid] > k)
        {
            right = mid-1;
        }else
        {
            left = mid +1;
        }
    }
    return ret;
}

int main()
{
    int k;
    scanf("%d", &k);
    for (int i = 0; i < sizeof(coins) / sizeof(coins[0]); i++)
    {
        if ( k == coins[i].amount)
        {
            printf("%s\n", coins[i].name);
            break;
        }
    }



    return 0;
}
