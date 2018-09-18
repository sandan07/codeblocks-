#include<stdio.h>
#include<string.h>

int main()
{
    char s1[100] = {0};
    char s2[100] = {0};
    char temp[100] = {0};
    gets(s1);
    gets(s2);

    while(strstr(s1,s2) != NULL)
    {
        int lens1 = strlen(s1);
        int lens2 = strlen(s2);

        strcpy(temp, strstr(s1, s2));
        int loc = strlen(temp);


        strcpy(s1+lens1-loc,temp+lens2);
    }
    puts(s1);


    return 0;

}
