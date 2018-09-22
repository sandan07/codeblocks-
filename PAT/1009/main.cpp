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
            ans[r][h++] = str[i]; //空格代表一个单词输入结束，所以不是空格就把当前字母放到当前的二维数组中去
        }else
        {
            ans[r][h] = '\0';   //如果是空格就证明当前的二维数组结束了
            r++;                //行+1进行下一个单词
            h = 0;              //回到第一位
        }
    }
    for(int i = r; i >= 0; i--)
    {
        printf("%s", ans[i]);
        if(i > 0) printf(" ");
    }

    return 0;
}
