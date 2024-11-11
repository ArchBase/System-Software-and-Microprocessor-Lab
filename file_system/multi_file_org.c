#include <stdio.h>
#include <string.h>

struct File{
	int id;
	char name[50];
};
struct Folder{
	int id;
	char name[50];
	struct File *files[10];
	struct Folder *parent, *folders[10];
	int file_index, folder_index;
};
struct Memory{
	struct Folder folders[50];
	struct File files[50];
	int folder_index, file_index;
};
	
struct Folder root_fol;
struct Folder *root, *current;
struct Memory memory;

void create_file(){
	printf("enter file name: ");
	scanf("%s", memory.files[memory.file_index].name);
	memory.files[memory.file_index].id = memory.file_index;
	current->files[current->file_index] = &memory.files[memory.file_index];
	current->file_index++;
	memory.file_index++;
	printf("File created");
}

void rename_file(){
	int i, choice;
	printf("\n");
	for(i=0; i<current->file_index; i++){
		if(current->files[i]->id == -1){
			continue;
		}
		printf("\n\t[%d] --> %s", i, current->files[i]->name);
	}
	printf("\n\t[%d] -> Cancel", i);
	printf("\n\nSelect file to rename: ");
	scanf("%d", &choice);
	if(choice == i){
		printf("Cancelled");
		return;
	}
	printf("Enter new name: ");
	scanf("%s", current->files[choice]->name);
	printf("\nFile renamed successfully");
}

void rename_folder(){
    int i, choice;
    printf("\n");
	for(i=0; i<current->folder_index; i++){
		if(current->folders[i]->id == -1){
			continue;
		}
		printf("\n\t[%d] --> %s", i, current->folders[i]->name);
	}
	printf("\n\t[%d] -> Cancel", i);
	printf("\n\nSelect folder to rename: ");
	scanf("%d", &choice);
    if(choice == i){
		printf("Cancelled");
		return;
	}
    printf("Enter new name: ");
	scanf("%s", current->folders[choice]->name);
	printf("\nFolder renamed successfully");
}

void desc_folder(){
	int i;
	printf("\n\nFolder name: %s\n\tFolders inside:", current->name);
	for(i=0; i<current->folder_index; i++){
        if(current->folders[i]->id == -1){
			continue;
		}
		printf("\n\t\t%s", current->folders[i]->name);
	}
	printf("\n\tFiles inside:");
	for(i=0; i<current->file_index; i++){
		if(current->files[i]->id == -1){
			continue;
		}
		printf("\n\t\t%s", current->files[i]->name);
	}
}

void create_folder(){
	printf("Enter folder name: ");
	scanf("%s", memory.folders[memory.folder_index].name);
	memory.folders[memory.folder_index].id = memory.folder_index;
	memory.folders[memory.folder_index].parent = current;
	memory.folders[memory.folder_index].folder_index = 0;
	memory.folders[memory.folder_index].file_index = 0;
	current->folders[current->folder_index] = &memory.folders[memory.folder_index];
	current->folder_index++;
	memory.folder_index++;
	printf("Folder created successfully");
}

void change_dir(){
	int i, choice;
	printf("Choose folder to change directory: \n");
	if(current->parent != NULL){
		printf("\n\t[9] --> parent directory");
	}
	for(i=0; i<current->folder_index; i++){
		printf("\n\t[%d] --> %s", i, current->folders[i]->name);
	}
	printf("\n\t[%d] -> Cancel", i);
	printf("\n\nEnter your choice: ");
	scanf("%d", &choice);
	if(choice == i){
		printf("Cancelled");
		return;
	}
	if(choice == 9){// parent
		if(current->parent == NULL){
			printf("Root folder doesn't have parent");
			return;
		}
		else{
			current = current->parent;
			printf("Folder changed to %s", current->name);
		}
	}
	else{
		current = current->folders[choice];
		printf("Folder changed to %s", current->name);
	}
}

	
void delete_file(){
	int i, choice;
	printf("\n");
	for(i=0; i<current->file_index; i++){
		if(current->files[i]->id == -1){
			continue;
		}
		printf("\n\t[%d] --> %s", i, current->files[i]->name);
	}
	printf("\n\t[%d] -> Cancel", i);
	printf("\n\nSelect file to delete: ");
	scanf("%d", &choice);
	if(choice == i){
		printf("Cancelled");
		return;
	}
	current->files[choice]->id = -1;
}

void delete_folder(){
    int i, choice;
    printf("\n");
	for(i=0; i<current->folder_index; i++){
		if(current->folders[i]->id == -1){
			continue;
		}
		printf("\n\t[%d] --> %s", i, current->folders[i]->name);
	}
	printf("\n\t[%d] -> Cancel", i);
	printf("\n\nSelect folder to delete: ");
    scanf("%d", &choice);
    if(choice == i){
        printf("Cancelled");
        return;
    }
    current->folders[choice]->id = -1;
}


int menu(){
	int choice;
	//printf("\n*******************************************************************************\n[1] --> Describe folder\n[2] --> Create file\n[3] --> Create folder\n[4] --> Change directory\n[5] --> Rename file\n[6] --> Delete file\n[7] --> Delete folder\n[8] --> Rename folder\n[9] --> Exit\n\nEnter your choice: ");
	printf("\n\nEnter your choice: ");
	scanf("%d", &choice);
	switch(choice){
		case 1: desc_folder();return 0;
		case 2: create_file();return 0;
		case 3: create_folder();return 0;
		case 4: change_dir();return 0;
		case 5: rename_file();return 0;
		case 6: delete_file();return 0;
        case 7: delete_folder();return 0;
        case 8: rename_folder();return 0;
		case 9: return 1;
		default: printf("Choose correct option");
	}
}


void main(){
	int i;
	memory.folder_index = 0;
	memory.file_index = 0;
	root_fol.id = 0;
	strcpy(root_fol.name, "root");
	current = &root_fol;
	root = &root_fol;
	current->file_index = 0;
	current->folder_index = 0;
	current->parent = NULL;

    printf("Created root folder\n");
	printf("\n*******************************************************************************\n[1] --> Describe folder\n[2] --> Create file\n[3] --> Create folder\n[4] --> Change directory\n[5] --> Rename file\n[6] --> Delete file\n[7] --> Delete folder\n[8] --> Rename folder\n[9] --> Exit\n\n");
	//printf("\n*******************************************************************************\n[1] --> Describe folder\n[2] --> Create file\n[3] --> Create folder\n[4] --> Change directory\n[5] --> Rename file\n[6] --> Delete file\n[7] --> Delete folder\n[8] --> Rename folder\n[9] --> Exit");
	for(i=1; i>0; i-=menu()){
		printf("\n\n\n*******************************************************************************");
	}
}