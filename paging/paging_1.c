#include <stdio.h>

void main(){
    int mem_size, pgm_size, nf, np, page_size, i, frames[10], pages[10];
    printf("Enter memory size: ");
    scanf("%d", &mem_size);
    printf("Enter program size: ");
    scanf("%d", &pgm_size);
    printf("Enter page size: ");
    scanf("%d", &page_size);

    nf = mem_size/page_size;
    if((pgm_size%page_size) == 0){
        np = pgm_size/page_size;
    }
    else{
        np = pgm_size/page_size;
        np++;
    }

    printf("Enter page table: \n");
    for(i=0; i<nf; i++){

    }
}