#include<stdio.h>

int main()
{
    int number;
    int cnt = 0;
    scanf("%d", &number);
    while( number != 1 )
    {
        if ( number % 2 == 0)
        {
            number = number / 2;
            cnt++;
        }else{
            number = (3 * number + 1) / 2;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
