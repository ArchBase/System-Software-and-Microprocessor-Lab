#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char label[10], opcode[10], operand[10], obj_code[10];
char optab[10][10] = {"START"};
int address;
FILE *input_file, *symtab_file, *output_file;

