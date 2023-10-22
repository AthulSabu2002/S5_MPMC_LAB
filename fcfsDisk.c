#include<stdio.h>
void main(){
    int array[100],head,totalHeadMom=0,i,j,n;
    printf("Enter the number of processes  : ");
    scanf("%d",&n);
    printf("Enter the sequence \n");
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    printf("Enter the initial head position : ");
    scanf("%d",&head);
    for(i=0;i<n;i++){
        if(array[i]>head){
            totalHeadMom=totalHeadMom+(array[i]-head);
            head=array[i];
        }
        else{
            totalHeadMom=totalHeadMom+(head-array[i]);
            head=array[i];
        }
    }
    printf("\n");
    printf("Total Head Movement is : %d",totalHeadMom);
    printf("\n");
}