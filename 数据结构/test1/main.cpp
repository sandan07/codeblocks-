#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    int a[] = {9, 4, 2, 5, 6, -1,};
    sort(a, a+6);
    for(int i = 0; i < 6; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}
