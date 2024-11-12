#include<stdio.h>

int fibo(int n){
    if(n==0 || n==1){
        return n;
    }else{
        return fibo(n-1)+fibo(n-2);
    }
}

int main (){

    int n;
printf("Enter the number of terms: ");
scanf("%d",&n);



printf("fibonacci series upto n terms: ");
 for(int i = 0; i<n; i++) {
        printf("%d ",fibo(i));
 
    }
     printf("\n");
}