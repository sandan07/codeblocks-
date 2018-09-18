#include <stdio.h>
#include <stdlib.h>
int sum = 0;
int n = 0;
int main()
{
    /*for(n = 0; n <=100 ;n++)
    {
        if (n %2 == 0)
        {
            sum += n;
        }else
        {
            continue;
        }
    }*/
    for( n = 0; n <= 100;n++)
    {
        if(n % 2 !=0) continue;
        sum += n;
    }

    printf("%d",sum);
    return 0;
}
