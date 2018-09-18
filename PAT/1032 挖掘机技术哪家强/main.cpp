#include<stdio.h>
#include<string.h>

int main()
{
    int number;
    int school[100010] = {0};//数组开的太小了，第一次测试点3未通过
    scanf("%d", &number);
    getchar();
    int schid = 0, score = 0;
    for (int i = 0; i < number; i++)
    {
        scanf("%d %d", &schid, &score);
        school[schid] += score;
    }
    int k = 1, max = -1;
    for (int i = 0; i <= number ; i++)
    {
        if (school[i] > max)
        {
            max = school[i];
            k = i;
        }
    }

    printf("%d %d\n", k , max);
    return 0;
}
