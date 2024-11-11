#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char address[10], label[10], opcode[10], operand[10], obj_code[10];
char optab[10][10] = {"START"};
int start=0, locctr=0;
FILE *input_file, *symtab_file, *output_file;

void pass1(){
    fscanf(input_file,"%s%s%s", label, opcode, operand);//read first line

    if(strcmp(opcode, "START") == 0){//Process first line
        start = atoi(operand);
        locctr = start;
        fprintf(output_file,"%s\t%s\t%s\t%s\n", "**",label,opcode,operand);
    }

    while(strcmp(opcode, "END") != 0){
        fscanf(input_file, "%s%s%s", label, opcode, operand);//read next line
        fprintf(output_file, "%d\t", locctr);

        if(strcmp(label, "**") != 0){//write to file if has label
            fprintf(symtab_file, "%s\t%d\n", label, locctr);
        }
        if(strcmp(opcode, "WORD")){
            locctr += 3;
        }
        else if(strcmp(opcode, "BYTE")){
            locctr += 1;
        }
        else if(strcmp(opcode, "RESW")){
            locctr += 3 * atoi(operand);
        }
        else if(strcmp(opcode, "RESB")){
            locctr += atoi(operand);
        }
        else{//opcode is instruction
            locctr += 3;
        }
        fprintf(output_file, "%s\t%s\t%s\n", label, opcode, operand);
    }
}

void main(){
    //open files
    input_file = fopen("input.txt", "r");
    symtab_file = fopen("symtab.txt", "w");
    output_file = fopen("output.txt", "w");

    //perform pass 1
    pass1();

    //close files
    fclose(input_file);
    fclose(output_file);
    fclose(symtab_file);
    
    printf("Done. check output files. \"output.txt\", \"symtab.txt\"\n");
}

