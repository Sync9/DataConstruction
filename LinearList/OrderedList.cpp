#include <iostream>
/*
 * Initialize the Ordered List
 * Add an element to the Ordered List
 * Delete an element from the Ordered List
 * Find an element in the Ordered List
 * Modify an element in the Ordered List
 **/
typedef struct OrderedList{
    int* head;
    int length;
    int size;
};
OrderedList init(int block);
void add(OrderedList* orderedList,int val,int idx);
void remove(OrderedList* orderedList,int idx);
int inquire(OrderedList* orderedList,int val);
int modify(OrderedList* orderedList,int val0,int val1);
void display(OrderedList orderedList);
int main() {
    using namespace std;
    int input=0;
    int input1=0;
    cout<<"Please input the number of the element in the ordered list"<<endl;
    cin>>input;
    OrderedList orderedList=init(input);
    cout<<"Please input the values of the element in the ordered list"<<endl;
    for(int i=0;i<orderedList.length;i++){
        cin>>orderedList.head[i];
    }
    display(orderedList);
    cout<<"Please input the value of the element you are going to insert into the ordered list"<<endl;
    cin>>input;
    cout<<"Please input the target index"<<endl;
    cin>>input1;
    add(&orderedList,input,input1);
    display(orderedList);
    cout<<"Please input the index you are going to delete"<<endl;
    cin>>input1;
    remove(&orderedList,input1);
    display(orderedList);
    cout<<"Please input the value of the element you are going to find"<<endl;
    cin>>input;
    input1=inquire(&orderedList,input);
    if(input1!=-1){
        cout<<"The address of the element in the ordered list is "<<endl;
        cout<<&orderedList.head[input1]<<endl;
    }
    else {
        cout << "The element is not exist" << endl;
    }
    cout<<"Please input the value of the element you are going to modify"<<endl;
    cin>>input;
    cout<<"Please input new value of the element"<<endl;
    cin>>input1;
    int temp = modify(&orderedList,input,input1);
    if(temp==-1){
        cout << "The element is not exist" << endl;
    }
    else display(orderedList);

}
void display(OrderedList orderedList){
    using namespace std;
    cout<<"The size of the ordered list is "<<orderedList.size<<" Bytes"<<endl;
    cout<<"The values of every element in the ordered list are as follows"<<endl;
    for(int i=0;i<orderedList.length;i++){
        cout<<orderedList.head[i]<<endl;
    }
    cout<<"The addresses of every element in the ordered list are as follows"<<endl;
    for(int i=0;i<orderedList.length;i++){
        cout<<&orderedList.head[i]<<endl;
    }
}
OrderedList init(int block){
    OrderedList orderedList;
    orderedList.head=(int*)malloc(sizeof(int)*block);
    if(orderedList.head==NULL) {
        std::cout<<"Fail to initialize the ordered list"<<std::endl;
        exit(0);
    }
    orderedList.length=block;
    orderedList.size=orderedList.length*sizeof(int);
    return orderedList;
}
void add(OrderedList* orderedList,int val,int idx){
    realloc(orderedList->head,(++orderedList->length)*sizeof(int));
    if(!orderedList->head){
        std::cout<<"Fail to reallocate memory for the ordered list"<<std::endl;
        exit(0);
    }
    if(idx>=orderedList->length) {
        std::cout << "Index out of bounds" << std::endl;
        exit(0);
    }
    int temp_cur=0;
    int temp_suc=0;
    temp_cur = orderedList->head[idx];
    orderedList->head[idx] = val;
    for (int i = idx + 1; i < orderedList->length; i++) {
        temp_suc = orderedList->head[i];
        orderedList->head[i] = temp_cur;
        temp_cur = temp_suc;
    }
}
void remove(OrderedList* orderedList,int idx){
    if(idx>=orderedList->length) {
        std::cout << "Index out of bounds" << std::endl;
        exit(0);
    }
    for(int i=idx+1;i<orderedList->length;i++)
        orderedList->head[i-1]=orderedList->head[i];
    orderedList->length--;
}
int inquire(OrderedList* orderedList,int val){
    for(int i=0;i<orderedList->length;i++)
        if(orderedList->head[i]==val) return i;
    return -1;
}
int modify(OrderedList* orderedList,int val0,int val1){
    int temp=inquire(orderedList,val0);
    if(temp!=-1){
        orderedList->head[inquire(orderedList,val0)]=val1;
    }
    else {
        return -1;
    }
}

