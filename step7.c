#include <stdio.h>

int main(void)
{
    int year;

    printf("西暦を入力してください：");
    scanf("%d",&year);

    if(year % 4 == 0)printf("夏季オリンピック\n");
    if(year % 2 == 0 && year % 4 != 0)printf("冬季オリンピック\n");
    if(year % 2 != 0)printf("オリンピックなし\n");

    return 0;
}