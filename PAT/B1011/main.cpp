#include<stdio.h>

struct
{
    long long a;
    long long b;
    long long c;
}T[100000];

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%lld %lld %lld", &T[i].a, &T[i].b, &T[i].c);
    }
    for(int i = 0; i < N; i++)
    {
        if(T[i].a + T[i].b > T[i].c)
            printf("Case #%d: true\n", i + 1);
        else printf("Case #%d: false\n", i + 1);
    }
    return 0;
}
