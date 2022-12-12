/*
using namespace std;
#include "List.h"
#include "Node.h"

template <class T>
class StackList{
    public:
        List<T> *lista;
        Node<T> *top;
        int maxSize;
        int size;

        StackList(int max){
            lista = new List<T>();
            top = lista->first;
            maxSize = max;
            size = 0;
        }

        void push(T value);
        T pop();
        //bool isEmpty(){ return top == -1;}
        //bool isFull(){ return top == maxSize-1};
};

template <class T>
void StackList<T>::push(T value){ // is fUll
    
    lista->insertFirst(value);
    top = lista->first;
    size++;
    
}

template <class T>
T StackList<T>::pop(){ // is empty
    
    T item = top->data;
    lista->deleteFirst();
    top = lista->first;
    size--;

    return item;
}*/