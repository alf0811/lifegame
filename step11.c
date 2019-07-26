#include <stdio.h>


int olympic(int year);

int main(void)
{
    int year,hold;
    printf("西暦を入力してください：");
    scanf("%d",&year);
    hold = olympic(year);

    switch(hold){
        case 0:
            printf("開かれない\n");
            break;
        case 1:
            printf("夏季五輪\n");
            break;
        case 2:
            printf("冬季五輪\n");
            break;
    };

    return 0;

}

int olympic(int year)
{
    if(year % 2 == 0){
        if(year % 4 == 0){
            return 1;
        } else {
            return 2;
        }
    } else {
        return 0;
    }

}