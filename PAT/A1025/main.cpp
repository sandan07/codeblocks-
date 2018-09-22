#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

struct Student
{
    char id[15];
    int score;
    int local_number;
    int local_rank;
}stu[300010];

bool cmp(Student a, Student b)
{
    if(a.score != b.score) return a.score > b.score;
    else return strcmp(a.id, b.id) < 0;
}

int main()
{
    int N, num = 0, K;
    scanf("%d", &N);    //考场号
    for(int i = 0;i < N; i++)
    {
        scanf("%d", &K); //考场人数
        for(int j = 0; j < K; j++)
        {
            scanf("%s %d", stu[num].id, &stu[num].score);
            stu[num].local_number = i + 1;
            num ++;
        }
        sort(stu + num - K, stu + num, cmp);
        stu[num - K].local_rank = 1;
        for(int j = num - K + 1; j < num ;j ++)
        {
            if(stu[j].score == stu[j-1].score)
            {
                stu[j].local_rank = stu[j-1].local_rank;
            }else
            {
                stu[j].local_rank = j + 1 - num + K;
            }
        }
    }
    printf("%d\n", num);
    sort(stu, stu + num, cmp);
    int r = 1;
    for(int i = 0; i < num; i++)
    {
        if( i > 0 && stu[i].score != stu[i-1].score)
            r = i + 1;
        printf("%s ", stu[i].id);
        printf("%d %d %d\n", r, stu[i].local_number, stu[i].local_rank);
    }
    return 0;
}
