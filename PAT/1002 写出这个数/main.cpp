#include<stdio.h>
#include<string.h>

int main()
{
    char str[110];      //�����ַ���
    gets(str);
    int sum = 0;
    //printf("%s",str);
    int len = strlen(str);
    for ( int i = 0 ; i < len ; i++)
    {
        sum += str[i] - '0';    //��������ȥ��str���ַ����ͣ�����1��ascii����49��Ҫת�����������Լ�ȥ0��ascii��48�Ϳ����ˡ�
    }

    //ȡ��sum��λ��
    int num = 0, ans[10];
    while(sum != 0)
    {
        ans[num] = sum % 10;
        num++;
        sum /= 10;
    }


    char a[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu",};

    for( int i = num - 1; i>= 0 ; i-- )
    {
        printf("%s", a[ans[i]]);
        if (i != 0)
        {
            printf(" ");
        }else
        {
            printf("\n");
        }
    }

    return 0;
}
