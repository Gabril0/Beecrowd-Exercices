#include <stdio.h>

void value(int x, int y){
    int temp;
    if(x>y){
        temp=x;
        x=y;
        y=temp;
    }
    if(x=y){printf("%d\n",x);}
    else{printf("%d\n",x);}


}

int main (){
    int number1, number2;
    scanf("%d %d",&number1, &number2);
    value(number1,number2);
    return 0;
}