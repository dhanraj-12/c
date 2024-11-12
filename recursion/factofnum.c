#include<stdio.h>

int fact(int num){
    if(num==0){
        return 1;
    }else {
        return num*fact(num-1);
    }

}

int main(){
    int num;
    printf("Enter a Number: ");
    scanf("%d",&num);

   int ans= fact(num);
    printf("The factorial of a given number is %d\n",ans);
}