#include <stdio.h>
#include <stdlib.h>

int main()
{
    double factdamage;
    int strength;
    double maxdamage = 256;

    printf("����������ɫ������:");
    scanf("%d",&strength);
    factdamage = maxdamage * (strength +100) / 100;
    printf("����ʵ���˺���:%.2lf\n",factdamage);

    return 0;
}
