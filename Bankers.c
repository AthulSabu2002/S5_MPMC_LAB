#include<stdio.h>
struct process{
    int max[10];
    int need[10];
    int alloc[10];
    int id;
    int vis;
};
struct process p[10];
int avail[10][10],i,j,np,nr,flag,comp,pid=0,seq[10],k=0,num=0;
int compare(){
    flag=0;
        for(j=0;j<nr;j++){
            if(p[i].need[j]>avail[pid][j]){
                flag=1;
                break;
            }
        }
    if(flag==0){
        return 0;
    }
    else
    return 1;
}
void bankers(){
    for(i=0;i<np;i++){
        if(p[i].vis==0){
            comp=compare();
            if(comp==0){
                for(j=0;j<nr;j++){
                    avail[pid+1][j]=avail[pid][j]+p[i].alloc[j];
                }
            printf("p%d\t",i); 
            p[i].vis=1;
            pid=pid+1;
            num=num+1;
            }
        }
    }
}
void main(){
    printf("Enter the number of processes : ");
    scanf("%d",&np);
    printf("Enter the number of resources : ");
    scanf("%d",&nr);
    printf("Enter the allocation matrix : ");
    printf("\n");
    for(i=0;i<np;i++){
        printf("Allocation of p%d : ",i);
        p[i].id=i;
        for(j=0;j<nr;j++){
           scanf("%d",&p[i].alloc[j]); 
        }
    }
    printf("Enter the Max matrix : ");
    printf("\n");
    for(i=0;i<np;i++){
        printf("Max of p%d : ",i);
        p[i].id=i;
        for(j=0;j<nr;j++){
           scanf("%d",&p[i].max[j]); 
        }
    }

    printf("Enter the available resources : ");
    for(i=0;i<nr;i++){
       scanf("%d",&avail[0][i]);
    }

    printf("Process \tNeed\t\n");
    for(i=0;i<np;i++){
        printf("p%d\t \t",p[i].id);
        for(j=0;j<nr;j++){
            p[i].need[j]=p[i].max[j]-p[i].alloc[j];
            printf("%d  ",p[i].need[j]);
            p[i].vis=0;
        }
        printf("\n");
    } 

    for(k=0;k<np;k++){
        if(p[k].vis==0){
            bankers();
        }
    }
    if(num==np){
        printf("\nThe system is safe ....");
    } 
    else
        printf("\nThe system is not safe...");
    
}