#include <stdio.h>
#include <stdlib.h>

struct Request{
    int position;
    int valid;
};

struct Request req_arr[10];
int no_of_req=0, direction=0, head_position=0, thm=0, end_position=0, start_position=0;

void input(){
    int i;
    printf("Enter no of requests: ");
    scanf("%d", &no_of_req);
    printf("Enter request queue: ");
    for(i=0; i<no_of_req; i++){
        scanf("%d", &req_arr[i].position);
        req_arr[i].valid = 1;
    }
    printf("Enter start direction(0 --> left, 1 --> right): ");
    scanf("%d", &direction);
    printf("Enter start position: ");
    scanf("%d", &start_position);
    printf("Enter end position: ");
    scanf("%d", &end_position);
    printf("Enter current head position: ");
    scanf("%d", &head_position);
}

void sort(){
    int i, j;
    struct Request temp;
    for(i=0; i<no_of_req; i++){
        for(j=0; j<no_of_req-i-1; j++){
            if(req_arr[j].position > req_arr[j+1].position){
                temp = req_arr[j];
                req_arr[j] = req_arr[j+1];
                req_arr[j+1] = temp;
            }
        }
    }
    //return;
    printf("\nSorted array: ");
    for(i=0; i<no_of_req; i++){
        printf("%d ", req_arr[i].position);
    }
    printf("\n");
}

int move_right(){
    int i=0;
    for(i=0; i<no_of_req; i++){
        if(req_arr[i].position > head_position && req_arr[i].valid == 1){// find next right req position
            printf("(%d --> %d)", head_position, req_arr[i].position);
            thm += req_arr[i].position - head_position;
            req_arr[i].valid = 0;
            head_position = req_arr[i].position;
            if(req_arr[i].position == end_position){
                return 1;//returning 1 means reached end of disk
            }
            return 0;//returning 0 means not reached end of disk
        }
    }
    return 1;
}

int move_left(){
    int i=0;
    for(i=no_of_req; i>=0; i--){
        if(req_arr[i].position < head_position && req_arr[i].valid == 1){
            printf("(%d --> %d)", head_position, req_arr[i].position);
            thm +=  head_position - req_arr[i].position;
            req_arr[i].valid = 0;
            head_position = req_arr[i].position;
            if(req_arr[i].position == start_position){
                return 1;
            }
            return 0;
        }
    }
    return 1;
}

void main(){
    input();
    sort();

    if(direction == 1){//left
        printf("Right: ");
        for(;move_right() != 1;);
        printf("\nLeft: ");
        for(;move_left() != 1;);
    }
    else{
        printf("Left: ");
        for(;move_left() != 1;);
        printf("\nRight: ");
        for(;move_right() != 1;);
    }
    printf("\n\nTotal Head Movement: %d\n", thm);
}
