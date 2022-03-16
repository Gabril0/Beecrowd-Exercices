#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int IsEven(int x, int y){
    int z;
    z=x+y;
    if(z%2==0){return true;}
    else{return false;}
}   

int main(){
    int cases, number1, number2;
    char name1[100],name2[100], type1[10], type2[10];
    int i;

    scanf("%d",&cases);
    for(i=0;i<cases;i++){
        scanf("%s", name1);
        scanf("%s", type1);
        scanf("%s", name2);
        scanf("%s", type2);
        scanf("%d %d",&number1, &number2);
        if((IsEven(number1, number2))==true){
            if(strcmp(type1,"PAR")==0){printf("%s\n", name1);}
            else{printf("%s\n", name2);}
        }
        else if((IsEven(number1, number2))==false){
            if(strcmp(type1,"IMPAR")==0){printf("%s\n", name1);}
            else{printf("%s\n", name2);}
        }


    }
    
    return 0;
}