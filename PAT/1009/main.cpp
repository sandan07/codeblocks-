#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char str[90];
    gets(str);
    int len = strlen(str);
    int r = 0, h = 0;
    char ans[90][90];
    for(int i = 0; i < len; i++)
    {
        if(str[i] != ' ')
        {
            ans[r][h++] = str[i]; //�ո����һ������������������Բ��ǿո�Ͱѵ�ǰ��ĸ�ŵ���ǰ�Ķ�ά������ȥ
        }else
        {
            ans[r][h] = '\0';   //����ǿո��֤����ǰ�Ķ�ά���������
            r++;                //��+1������һ������
            h = 0;              //�ص���һλ
        }
    }
    for(int i = r; i >= 0; i--)
    {
        printf("%s", ans[i]);
        if(i > 0) printf(" ");
    }

    return 0;
}
