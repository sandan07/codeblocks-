#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int price;
    int price1;int price2;int price3;int price4;int price5;int price6;int price7;
    int count = 0;
    int guessprice;
    srand((unsigned)time(NULL));
    price1 = rand() % 10;
    price2 = rand() % 10;
    price3 = rand() % 10;
    price4 = rand() % 10;
    price5 = rand() % 10;
    price6 = rand() % 10;
    price7 = rand() % 10;
    price = price1 + price2 *10 +price3 * 100 + price4 * 1000 + price5 * 10000 + price6 * 100000 + price7 * 1000000;
    for(;;count++)
    {
        printf("��������Ʒ�۸�:");
        scanf("%d",&guessprice);
        if(guessprice > price)
        {
            printf("����\n");
        }else if(guessprice < price)
        {
            printf("С��\n");
        }
        else
        {
            count++;
            break;
        }
    };
    printf("��¶���,һ������%d��",count);
    return 0;
}
