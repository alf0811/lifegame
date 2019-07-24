#include <stdio.h>

int main(void)
{
    int point;

    do{
        printf("テストの点数を入力してください：");
        scanf("%d",&point);
    } while (point > 100);

    printf("テストの点数は%d点です。\n",point);

    return 0;
}