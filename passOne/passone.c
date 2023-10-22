#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char  opcode[200], operand[200], label[200], mnemonics[200], symbol[200];
int locctr, start, found = 0, op, prev_locctr;
FILE *intermediate, *symtab, *optab, *input;
int search_optab(){
    char search[200];
    while(fscanf(optab,"%s",search)!=EOF){
        if(strcmp(search,opcode) ==0 ){
            found = 1;
            return found;
        }
    }
}
void main(){
    input = fopen("input.txt","r");
    optab = fopen("optab.txt","r");
    intermediate = fopen("intermediate.txt","w");
    symtab = fopen("symtab.txt","w");
    fscanf(input,"%s\t%s\t%s",label,opcode,operand);
    
    if(strcmp(opcode, "START") == 0){
        start = atoi(operand);
        locctr = start;
        fprintf(intermediate,"\t%s\t%s\t%s\n",label,opcode,operand);
        fscanf(input,"%s\t%s\t%s",label,opcode,operand);
    }
    else{
        locctr = 0;
    }

    do{
        prev_locctr = locctr;
        if(strcmp(label,"**")!=0){
            fprintf(symtab,"%s\t%d\n",label,locctr);   
        }

        if(opcode){
            if(strcmp(opcode,"WORD") ==0 )
            locctr = locctr + 3;
            else if(strcmp(opcode,"RESW") ==0 ){
                op = atoi(operand);
                locctr = locctr +(3 * op);
            }
            else if(strcmp(opcode,"RESB") ==0 ){
                op = atoi(operand);
                locctr = locctr + op;
            }
            else if(strcmp(opcode,"BYTE") ==0 ){
                locctr = (locctr + strlen(operand)) - 3;
            }
            else{
                found = search_optab();
                if(found!=1){
                    printf("The opcode %s not found in optab.",opcode);
                    exit(0);
                }
                locctr = locctr + 3;
            }
            fprintf(intermediate,"%d\t%s\t%s\t%s\n",prev_locctr,label,opcode,operand);
            found = 0;
        }
        fscanf(input,"%s\t%s\t%s\n",label,opcode,operand);
    }while (strcmp(opcode, "END") != 0);
    fprintf(intermediate,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
    fclose(input);
    fclose(optab);
    fclose(intermediate);
    fclose(symtab);
    printf("success....\n");
    printf("The length of program is : %d",locctr-start);
}
