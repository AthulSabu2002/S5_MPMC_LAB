#include<stdio.h>
struct process{
    int at,bt,wt,ct,id,tat;
};
struct process p[10];
int i,j,k=0,n=1,size,current_ct=0,smallest_bt,current,vis[10],CT[10];
float Total_WT,Total_TAT;
void shortest_job(){
    smallest_bt=1000000;
    for(i=1;i<size;i++){
        if(p[i].at>current_ct)
            break;
        else{
            if((p[i].bt<smallest_bt)&&(vis[i]==0)){
                smallest_bt=p[i].bt;
                current=i;
            }
        }
    }
    current_ct=current_ct+smallest_bt;
    p[current].ct=current_ct;
    vis[current]=1;
    printf("  p%d  |",p[current].id);
    CT[n++]=current_ct;
    k++;
}
void main(){
    printf("Enter the number of processes : ");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        printf("\nEnter arrival time of process%d : ",i);
        scanf("%d",&p[i].at);
        printf("\nEnter burst time of process%d : ",i);
        scanf("%d",&p[i].bt);
        p[i].id=i;
    }
    for(i=0;i<size;i++){
        for(j=i+1;j<size;j++){
            if(p[i].at>p[j].at){
                struct process temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
    }
    for(i=0;i<size;i++)
        vis[i]=0;
    p[0].ct=p[0].bt;
    current_ct=p[0].ct;
    vis[0]=1;
    CT[0]=current_ct;
    printf("|   p%d  |",p[current].id);
    for(i=0;i<size;i++){
        if(vis[i]==0){
            shortest_job();
            if(k==size)
            break;
            else
            i=0;
        }
    } 
    printf("\n0");
    for(i=0;i<size;i++)
        printf("      %d",CT[i]);   
    for(i=0;i<size;i++){
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        Total_TAT = Total_TAT + p[i].tat;
        Total_WT = Total_WT + p[i].wt;
    }
    printf("\nprocess     burst time    Arrival Time    Turn Around Time  WaitingTime\n");
    for(i=0;i<size;i++)
        printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].bt,p[i].at,p[i].tat,p[i].wt);

    printf("Total Turn Around Time is :  %f\n",Total_TAT);
    printf("Total Waiting Time is :  %f\n",Total_WT);
    printf("Average Turn Around Time is :  %f\n",Total_TAT/size);
    printf("Average Waiting Time  is :  %f\n",Total_WT/size); 
}