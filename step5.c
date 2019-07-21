#include <stdio.h>

int main(void)
{
    int juice,milk,money,payment,charge;
    double tax;

    juice = 198;
    milk = 138;
    money = 1000;
    tax = 1.05;

    payment = ((juice + milk*2)* tax);
    charge = money - payment;
    printf("%d円\n",charge);

    return 0;
}