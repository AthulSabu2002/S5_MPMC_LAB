#include<stdio.h>
struct process{
    int bt,ct,id,prt,wt,tat;
};
struct process p[10];
int n,i,j,Total_TAT=0,Total_WT=0;
float avgTAT,avgWT;
void main(){
    printf("Enter the number of processes");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the burst time of process  p%d : ",i+1);
        scanf("%d",&p[i].bt);
        printf("Enter the priority of process p%d : ",i+1);
        scanf("%d",&p[i].prt);
        p[i].id=i;
        printf("\n");
    }

    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j].prt>p[j+1].prt){
                struct process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            } 
        }
    }

    p[0].ct=p[0].bt;
    for(i=1;i<n;i++){
        p[i].ct=p[i].bt+p[i-1].ct;
    }

    for(i=0;i<n;i++){
        p[i].tat=p[i].ct;
    }
    p[0].wt=0;
    for(i=1;i<n;i++){
        p[i].wt=p[i].tat-p[i].bt;
    }


    printf("Gantt Chart \n");
    printf("|");
    for(i=0;i<n;i++){
        printf("    p%d    |",p[i].id);
    }
    printf("\n0");
    for(i=0;i<n;i++){
        printf("          %d",p[i].ct);
    } 

    printf("\nprocess           TAT            WT\n");
    for(i=0;i<n;i++){
        printf("p%d\t\t%d\t\t%d\n",p[i].id,p[i].tat,p[i].wt);
    }
    
    for(i=0;i<n;i++){
        Total_TAT = Total_TAT + p[i].tat;
    }
    avgTAT=Total_TAT/n;
    
    for(i=0;i<n;i++){
        Total_WT = Total_WT + p[i].wt;
    }
    avgWT=Total_WT/n;

    printf("Total Turn Around Time :  %d\n",Total_TAT);
    printf("Total Waiting Time :  %d\n",Total_WT);
    printf("Average Turn Around Time :  %f\n",avgTAT);
    printf("Average Waiting Time :  %f\n",avgWT);
}