#include<stdio.h>
struct process{
    int bt,wt,id,tat,rt,ct;
};
struct process p[10];
int i,j,size,ts,n=0,CT[100],current_ct=0;
float Total_TAT=0,Total_WT=0;
void RoundRobin(struct process p[]){
    for(i=0;i<size;i++){
        if(p[i].rt>ts){
                printf("  p%d  |",p[i].id);
                p[i].rt=p[i].rt-ts;
                current_ct=current_ct+ts;
                p[i].ct=current_ct;
                CT[n]=CT[n-1]+ts;
                n++;
        }
        else if(p[i].rt>0&&p[i].rt<=ts){
            printf("  p%d  |",p[i].id);
            CT[n]=CT[n-1]+p[i].rt;
            current_ct=current_ct+p[i].rt;
            p[i].ct=current_ct;
            p[i].rt=0;
            n++;
        }
    }         
    for(i=0;i<size;i++)
        if(p[i].rt>0)
            RoundRobin(p);     
}
void main(){
    printf("Enter the number of processes : ");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        printf("\nEnter burst time of process%d : ",i);
        scanf("%d",&p[i].bt);
        p[i].id=i;
        p[i].rt=p[i].bt;
    }
    printf("Enter the Time Slice for the processes  :  ");
    scanf("%d",&ts);
    printf("Gantt chart\n|");
    CT[0]=0;
    RoundRobin(p);
    printf("\n0");
    for(i=0;i<n;i++){
        printf("      %d",CT[i]);
    } 
    for(i=0;i<size;i++){
        p[i].tat=p[i].ct;
        p[i].wt=p[i].tat-p[i].bt;
        Total_TAT = Total_TAT + p[i].tat;
        Total_WT = Total_WT + p[i].wt;
    }
    printf("\nprocess     burst time    Turn Around Time  WaitingTime\n");
    for(i=0;i<size;i++){
        printf("p%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].bt,p[i].tat,p[i].wt);
    }
    printf("Total Turn Around Time is :  %f\n",Total_TAT);
    printf("Total Waiting Time is :  %f\n",Total_WT);
    printf("Average Turn Around Time is :  %f\n",Total_TAT/size);
    printf("Average Waiting Time  is :  %f\n",Total_WT/size); 
}
