#include<stdio.h>

int main()
{
    int sgn = 0 ;
    char *a[5] = {  "Unreadable",
                    "Barely readable, occasional words distinguishable",
                    "Readable with considerable difficulty",
                    "Readable with practically no difficulty",
                    "Perfectly readable"};
    char *b[9] = {  "Faint signals, barely perceptible",
                    "Very weak signals",
                    "Weak signals",
                    "Fair signals",
                    "Fair good signals",
                    "Good signals",
                    "Moderately strong signals",
                    "Strong signals",
                    "Extremely strong signals"};
    scanf("%d", &sgn);
    if( (sgn / 10) >= 1 && (sgn / 10 <= 5) && (sgn % 10 != 0) && (sgn % 10 <=9))
    {
        printf("%s, %s.", b[(sgn % 10) - 1], a[(sgn / 10) - 1]);
    }else{
        printf("Error");
    }
    return 0;

}
