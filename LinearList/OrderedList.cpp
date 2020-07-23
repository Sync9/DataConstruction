#include <iostream>
typedef struct OrderedList{
    int* head;
    int length;
    int size;
};
OrderedList init(int block);
int main() {
    using namespace std;
    int input=0;
    cout<<"Please input the number of the element in the ordered list"<<endl;
    cin>>input;
    OrderedList orderedList=init(input);
    cout<<"Please input the values of the element in the ordered list"<<endl;
    for(int i=0;i<orderedList.length;i++){
        cin>>orderedList.head[i];
    }
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
