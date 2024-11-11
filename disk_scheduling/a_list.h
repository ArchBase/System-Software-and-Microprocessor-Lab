
struct a_Int{
    int value;
    short int valid=1;
};

struct a_Int_List{
    struct a_Int list[100];
    int index=0;
};

void a_append(int value, struct a_Int_List *list_arg){
    list_arg->list[list_arg->index].value = value;
    list_arg->list[list_arg->index].valid = 1;
    list_arg->index += 1;
}

int a_get_element_by_index(int i, struct a_Int_List *list_arg){
    
    return list_arg->list[i].value;
}

void a_delete(int i, struct a_Int_List *list_arg){
    list_arg->list[i].valid = 0;
}





