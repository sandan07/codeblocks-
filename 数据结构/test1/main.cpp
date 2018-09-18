#include<stdio.h>

int main()
{
    int i;
    scanf("%d", &i);
    int *p = &i;
    printf("%p", p);
    return 0;
}
