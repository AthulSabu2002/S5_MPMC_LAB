#include<stdio.h>
void main(){
 int i,j,request[10],seekTime=0,n,temp,head,mov,diskSize;
 printf("Enter the diskSize : ");
 scanf("%d",&diskSize);
 diskSize=diskSize-1;
 printf("Enter the number of requests : ");
 scanf("%d",&n);
 printf("Enter the request sequence : ");
 for(i=0;i<n;i++){
 scanf("%d",&request[i]);
 }
 printf("Enter the head position : ");
 scanf("%d",&head);
 for(i=0;i<n;i++){
 for(j=0;j<n-i-1;j++){
 if(request[j]>request[j+1]){
 temp=request[j];
 request[j]=request[j+1];
 request[j+1]=temp;
 }
 }
 }
 i=0;
 while(request[i]<head){
 i=i+1;
 }
 i--;

 seekTime=(diskSize-head)+diskSize+(request[i]);

 printf("\nSeek Time : %d",seekTime);
 printf("\n");
 }