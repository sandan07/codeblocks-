#include <stdio.h>
#include <stdlib.h>

int main()
{
    double factdamage;
    int strength;
    double maxdamage = 256;

    printf("请玩家输入角色的力量:");
    scanf("%d",&strength);
    factdamage = maxdamage * (strength +100) / 100;
    printf("武器实际伤害是:%.2lf\n",factdamage);

    return 0;
}
