#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int max = 256;

//�ж�

bool judge(char str[])
{
    int len = strlen(str);
    for( int i = 0; i < len / 2; i++)
    {
        if(str[i] != str[len - i - 1]) // ��ǰλ�ͶԳ�λ���Ƿ�һ��
        {
            return false;
        }
    }
    return true;
}

int main()
{
    char str[max];
    while(gets(str))
    {
        bool flag = judge(str);
        if (flag == true) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
