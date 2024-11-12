#include <stdio.h>

int ack(int m,int n){

    if(m==0){
        return n+1;

    }else if(n==0 && n>0){
        return ack(m-1,1);
    }else if(m>0,n>0){
        return ack(m-1,ack(m,n-1));
    }

}

int main(){
    int m,n;
    printf("Enter numbers to insert to generate ackerman number: ");
    scanf("%d %d",&m,&n);

     int x= ack(m,n);
     printf("The random number genrated by funtion is %d", x);
}