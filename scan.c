#include<stdio.h>
void main(){
    int array[100],head,totalHeadMom=0,i,j,n,mov,diskSize;
    printf("Enter the disk size : ");
    scanf("%d",&diskSize);
    diskSize--;
    printf("Enter the number of processes  : ");
    scanf("%d",&n);
    printf("Enter the sequence \n");
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    printf("Enter the initial head position : ");
    scanf("%d",&head);

    printf("Press 0 for low and 1 for high :  ");
    scanf("%d",&mov);

    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }

    if(mov==0){
        totalHeadMom=head+array[n-1];
    }
    else{
        totalHeadMom=(diskSize-head)+(diskSize-array[0]);
    }
    printf("\n");
    printf("Total Head Movement is : %d",totalHeadMom);
    printf("\n");
}