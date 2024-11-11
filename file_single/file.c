#include <stdio.h>
#include <string.h>

struct File{
    char name[50];
    int id;
};
struct Folder{
    char name[50];
    struct File *files[100];
    struct Folder *folders[100];
    int file_index, folder_index, id;
};
struct Memory{
    struct File files[100];
    struct Folder folders[100];
    int file_index, folder_index;
};

struct Memory memory;
struct Folder *current, *root;



void new_file(){
    printf("\nEnter file name: ");
    scanf("%s", memory.files[memory.file_index].name);
    memory.files[memory.file_index].id = memory.file_index;
    memory.file_index += 1;
    current->files[current->file_index] = &memory.files[memory.file_index];
    current->file_index += 1;
    printf("created new file. global_id=%d, folder_id=%d", memory.file_index-1, current->file_index-1);
}

void list_files(){
    int i;
    printf("\n%s", current->name);
    for(i=0; i<current->file_index; i++){
        printf("\n\t--%s", current->files[i]->name);
    }
}

int input(){
    int choice;
    printf("\n\nEnter your option: ");
    scanf("%d", &choice);
    
    switch(choice){
        case 0:{
            new_file();
            break;
        }
        case 1:{
            list_files();
            break;
        }
    }
    return 0;
}

void main(){
    //print instructions
    printf("\n0 -> New file\n1 -> New folder\n");

    //init memory
    memory.file_index = 0;
    memory.folder_index = 0;
    printf("\nCreated memory");

    //create root folder
    strcpy(memory.folders[memory.folder_index].name, "root");
    memory.folders[memory.folder_index].id = memory.folder_index;
    memory.folders[memory.folder_index].file_index = 0;
    memory.folders[memory.folder_index].folder_index = 0;
    root = &memory.folders[memory.folder_index];
    current = &memory.folders[memory.folder_index];
    memory.folder_index += 1;
    root->file_index = 0;
    root->folder_index=0;
    printf("\nCreated root folder");

    for(;input() != 1;);
}

