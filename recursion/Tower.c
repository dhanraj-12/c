#include<stdio.h>

int step_count=0;

void towerofhanoi(int n,char source, char dest,char aux){
    if(n==0){
        return ;
    }

    towerofhanoi(n-1,source,aux,dest);
    step_count++;
    printf("move disk %d from %c rod to %c rod\n ",n,source,dest);
    towerofhanoi(n-1,aux,dest,source);
    

}
int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    towerofhanoi(n,'A','B','C');
    printf("Total number of steps: %d\n",step_count);
    return 0;
    
}