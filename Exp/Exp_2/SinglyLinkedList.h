#ifndef DC_EXP_2_SINGLYLINKEDLIST_H
#define DC_EXP_2_SINGLYLINKEDLIST_H

typedef struct SinglyLL{
    int data;
    struct SinglyLL* next;
}SLL;

class SinglyLinkedList {
private:
    SLL* head;
    int len;
public:
    SinglyLinkedList();
    SinglyLinkedList(int num);
    ~SinglyLinkedList();
    void insertIntoSLL(int val);
    void reverseSLL();
    bool isEmpty() const;
    void showSLL();
};
#endif //DC_EXP_2_SINGLYLINKEDLIST_H
