include <iostream>
#include "SinglyLinkedList.h"
int main() {
    int input=0;
    std::cout<<"How long the ordered singly linked list are you going to generate?"<<std::endl;
    std::cin>>input;
    auto* sll=new SinglyLinkedList(input);
    sll->showSLL();
    std::cout<<"Please input the number you want to insert into the ordered singly linked list"<<std::endl;
    std::cin>>input;
    sll->insertIntoSLL(input);
    sll->showSLL();
    std::cout<<"Now, the ordered singly linked list will be reversed"<<std::endl;
    sll->reverseSLL();
    sll->showSLL();
    return 0;
}
