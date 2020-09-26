#include "iostream"
#include "SinglyLinkedList.h"
SinglyLinkedList::SinglyLinkedList() {
    head= nullptr;
    len=0;
}
SinglyLinkedList::SinglyLinkedList(int num) {
    len=0;
    head=new SLL;
    SLL* ptr=head;
    SLL* node;
    for(int i=1;i<=num;i++){
        if(i==1){
            ptr->data=i;
            ptr->next= nullptr;
        }
        else{
            node=new SLL;
            node->data=i;
            node->next= nullptr;
            ptr->next=node;
            ptr=ptr->next;
        }
        len++;
    }
}
SinglyLinkedList::~SinglyLinkedList(){
    if(!isEmpty()){
        SLL* ptr=head->next;
        while(ptr){
            delete head;
            head=ptr;
            ptr=ptr->next;
        }
    }
}
bool SinglyLinkedList::isEmpty() const{
    return len==0;
}
void SinglyLinkedList::insertIntoSLL(int val) {
    if(isEmpty()) {
        head->data=val;
        head->next= nullptr;
    }
    else{
        SLL* node=new SLL;
        node->data=val;
        node->next= nullptr;
        SLL* cur=head;
        SLL* pri=head;
        while(cur&&cur->data<val){
            pri=cur;
            cur=cur->next;
        }
        if(cur == nullptr) pri->next=node;
        else{
            cur==pri?head=node:pri->next=node;
            node->next=cur;
        }
    }
    len++;
}
void SinglyLinkedList::reverseSLL() {
    if(isEmpty()) std::cout<<"Empty Linked List"<<std::endl;
    else {
        SLL *ptr = head;
        SLL *ptr_sav;
        SLL *sav_sav= nullptr;
        while (ptr) {
            head = ptr;
            ptr_sav = ptr;
            ptr = ptr->next;
            ptr_sav->next = sav_sav;
            sav_sav=ptr_sav;
        }
    }
}
void SinglyLinkedList::showSLL() {

    if(isEmpty()) std::cout<<"Empty Linked List"<<std::endl;
    else {
        std::cout<<"The data in the ordered linked list is as follows"<<std::endl;
        SLL *ptr = head;
        while (ptr) {
            std::cout << ptr->data<<"\t";
            ptr = ptr->next;
        }
        std::cout<<std::endl;
    }
}
