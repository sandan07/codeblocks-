#include<stdio.h>

void maxmin(int a[], int len, int *max, int *min);

int main()
{
    int a[] = {1,2,3,4,5,6,7,8,9,11,56,48,312,45,44,};
    int min, max;
    maxmin(a,sizeof(a) / sizeof(a[0]), &max, &min);
    printf("max:%d,min:%d", max, min);
    return 0;
}

void maxmin(int a[], int len, int *max, int *min)
{
    *max = *min = a[0];
    for(int i = 0; i < len ; i++)
    {
        if (a[i] < *min)
        {
            *min = a[i];
        }
        if (a[i] > *max)
        {
            *max = a[i];
        }
    }
}
