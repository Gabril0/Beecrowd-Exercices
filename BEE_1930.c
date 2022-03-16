#include <stdio.h>

int main(){
    int number1,number2,number3,number4,math;

    scanf("%d %d %d %d", &number1, &number2, &number3, &number4);
    math=(number1 + number2 + number3 + number4)-3;
    printf("%d\n", math);

    return 0;
}