#include <iostream>
typedef struct SinglyLinkedList{
    int data;
    struct SinglyLinkedList* next;
}slink;
slink* init();
void add(slink* head,int data);
void display(slink* head);
void find(slink* head,int data);
void remove(slink* head,int data);
int main() {
    int input=0;
    slink* head=init();
    display(head);
    std::cout<<"Please input the number you want to add to the singly linked list"<<std::endl;
    std::cin>>input;
    add(head,input);
    display(head);
    std::cout<<"Please input the number you want to find"<<std::endl;
    std::cin>>input;
    find(head,input);
    std::cout<<"Please input the number you want to delete"<<std::endl;
    std::cin>>input;
    remove(head,input);
    display(head);
    return 0;
}
slink* init(){
    int input=0;
    slink* head=(slink*)malloc(sizeof(slink));
    head->data=0;
    head->next=nullptr;
    std::cout<<"Please input the number you want to save to the singly linked list"<<std::endl;
    std::cout<<"Input -1 to end the input procedure"<<std::endl;
    std::cin>>input;
    while(input!=-1){
        slink* node=(slink*)malloc(sizeof(slink));
        if(node== nullptr) exit(0);
        node->data=input;
        add(head,input);
        std::cout<<"Please input the number you want to save to the singly linked list"<<std::endl;
        std::cout<<"Input -1 to end the input procedure"<<std::endl;
        std::cin>>input;
    }
    return head;
}
void add(slink* head,int data){
    slink* cur_ptr=(slink*)malloc(sizeof(slink));
    slink* pre_ptr=(slink*)malloc(sizeof(slink));
    cur_ptr=head->next;
    pre_ptr=head->next;
    slink* node=(slink*)malloc(sizeof(slink));
    if(node == nullptr) exit(0);
    node->data=data;
    node->next= nullptr;
    while(cur_ptr&&cur_ptr->data<=node->data) {
        pre_ptr=cur_ptr;
        cur_ptr = cur_ptr->next;
    }
    if(cur_ptr==pre_ptr) {
        head->next = node;
        node->next=cur_ptr;
    }
    else {
        pre_ptr->next = node;
        node->next = cur_ptr;
    }
    cur_ptr= nullptr;
    pre_ptr= nullptr;
    free(cur_ptr);
    free(pre_ptr);
}
void display(slink* head){
    slink* head_ptr=(slink*)malloc(sizeof(slink));
    head_ptr=head->next;
    while(head_ptr) {
        std::cout << head_ptr->data << std::endl;
        head_ptr=head_ptr->next;
    }
    head_ptr= nullptr;
    free(head_ptr);
}
void find(slink* head,int data){
    slink* head_ptr=(slink*)malloc(sizeof(slink));
    head_ptr=head->next;
    while(head_ptr&&head_ptr->data!=data) {
        head_ptr=head_ptr->next;
    }
    if(head_ptr== nullptr) std::cout<<"It's not exist"<<std::endl;
    else std::cout << head_ptr->data << std::endl;
    head_ptr= nullptr;
    free(head_ptr);
}
void remove(slink* head,int data){
    slink* cur_ptr=(slink*)malloc(sizeof(slink));
    slink* pre_ptr=(slink*)malloc(sizeof(slink));
    cur_ptr=head->next;
    pre_ptr=head->next;
    while(cur_ptr&&cur_ptr->data!=data){
        pre_ptr=cur_ptr;
        cur_ptr=cur_ptr->next;
    }
    if(cur_ptr==pre_ptr){
        head->next=cur_ptr->next;
        free(cur_ptr);
        pre_ptr = nullptr;
        free(pre_ptr);
    }else {
        if (cur_ptr == nullptr) {
            std::cout << "It's not exist" << std::endl;
            pre_ptr = nullptr;
            cur_ptr = nullptr;
        } else {
            pre_ptr->next = cur_ptr->next;
            pre_ptr = nullptr;
        }
        free(cur_ptr);
        free(pre_ptr);
    }
}

