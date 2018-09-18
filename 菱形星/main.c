#include <stdio.h>
#include <stdlib.h>
int i = 0;
int j = 0;
int main()
{
    for (i = 0 ; i < 4 ; i++)
    {
        for(j = 0;j <= 2 - i;j++)
        {
            printf(" ");
        }
        for(j = 0; j <= 2 * i;j++)
        {
            printf("*");
        }
        printf("\n");
    }







 /*   for(i = 0 ; i < 7 ; i++)
    {
        for (n = 0 ; n < 8 ; n++)
        {
            if (i <= 3)
            {
                if (n < (3 - i) || n > (i + 3))
                {
                    printf(" ");
                }else
                {
                    printf("*");
                };
            }else
            {
                if (n < (i - 3) || n > (9 - i))
                {
                    printf(" ");
                }else
                {
                    printf("*");
                }
            };
        };
        printf("\n");
    };
    */
    return 0;
}


