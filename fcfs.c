#include<stdio.h>
struct process{
    int at,bt,wt,ct,id,tat;
};
struct process p[10];
int i,j,size;
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

    //sorting
    for(i=0;i<size;i++){
        for(j=0;j<size-i-1;j++){
            if(p[j].at>p[j+1].at){
                struct process temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            } 
        }
    }

    //calculations
    p[0].ct=p[0].bt;
    p[0].wt=0;
    for(i=1;i<size;i++){
        p[i].ct=p[i].bt+p[i-1].ct;
        p[i].wt=p[i].tat-p[i].bt;
    }
    for(i=0;i<size;i++){
        p[i].tat=p[i].ct-p[i].at;
    }
    //Gantt chart
    printf("Gantt Chart \n");
    for(i=0;i<size;i++){
        printf("|    p%d    |",p[i].id);
    }
    printf("\n0");
    for(i=0;i<size;i++){
        printf("            %d",p[i].ct);
    }

    printf("\nprocess       burst time     Arrival Time   Turn Arount Time  WaitingTime\n");
    for(i=0;i<size;i++){
        printf("p%d\t\t%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].bt,p[i].at,p[i].tat,p[i].wt);
    }
}