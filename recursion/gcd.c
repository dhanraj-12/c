#include<stdio.h>

int gcd(int a , int b){

if (a==0){
    return b;
}else if(b==0){
    return a;
}else {
    return gcd(b,a%b);
}
}
int main(){

int a,b;
printf("Enter 2 numbers: ");
scanf("%d %d",&a,&b);

int ans=gcd(a,b);
printf("Gcd of given two numbers is %d",ans);

}