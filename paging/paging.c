#include <stdio.h> 
void main() 
{ 
    int i,n,p[20],mem,pgmsize,ps,np,nf,frame,add,off,f=0; 
    printf("PAGING"); 
    printf("\nENTER SIZE OF MEMORY: "); 
    scanf("%d",&mem); 
    printf("\nENTER SIZE OF PROGRAM: "); 
    scanf("%d",&pgmsize); 
    printf("\nENTER SIZE OF PAGE: "); 
    scanf("%d",&ps); 
    nf=mem/ps; 
    if(pgmsize%ps==0) 
        np=pgmsize/ps; 
    else 
    { 
        np=pgmsize/ps; 
        np++; 
    } 
    printf("\nNO. OF FRAMES: %d\nNO. OF PAGES: %d",nf,np); 
    printf("\n\nENTER PAGE TABLE:\n"); 
    for(i=0;i<np;i++) 
    { 
        printf("P%d: ",i); 
        scanf("%d",&p[i]); 
    } 
    printf("\n\nPAGE TABLE\nPAGES\tFRAMES "); 
    for(i=0;i<np;i++) 
        printf("\n%d\t%d",i,p[i]); 
    printf("\n\nENTER THE LOGICAL ADDRESS: "); 
    scanf("%d%d",&add,&off); 
    for(i=0;i<np;i++) 
    { 
        if(i==add) 
        { 
            frame=p[i]; 
            f=1; 
            break; 
        } 
    } 
    if(f==1) 
        printf("\nPHYSICAL ADDRESS: %d %d",frame,off); 
    else 
        printf("\nPAGE NOT FOUND"); 
}