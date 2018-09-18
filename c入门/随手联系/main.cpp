#include<stdio.h>

int main()
{
    int a[] = {0};
    int *p = a;
    while(p[0] == a[0])
    {
        printf("1");
    }
    return 0;
}
