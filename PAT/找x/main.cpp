#include<stdio.h>


int main()
{
    int n,x;
    scanf("%d", &n);
    int a[250] = {0};
    for (int i = 0; i < n ; i++)
    {
        scanf("%d", &a[i]);
    }

    scanf("%d", &x);
    int k = 0;
    for(k = 0 ;k < n ; k++)
    {
        if ( a[k] == x)
        {
            printf("%d\n", k);
            break;
        }
    }
    if (k == n)
    {
        printf("-1\n");
    }
    return 0;
}
