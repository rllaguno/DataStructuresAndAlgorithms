#define List_h

#include <iostream>
using namespace std;
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include "Node.h"
#include "Datos.h"

template<class T>
class List{	
	
	public:
		Node<T> *first; //head = first   // puntero al primer nodo
		int size;

		List() 
		{	first = nullptr; 
			size = 0;
		}
	
		int getSize(){ return size; }
		T find(int index);
		void insertLast(T data);
		void insertAtIndex(T data, int position);
    void deleteFirst();
};

template<class T>
T List<T>::find(int index){
	Node<T> *aux = first;
    Node<T> *head = first;
    if(index>size-1){
      return head->data; // regresa valor primero de lista
    }
    for(int i = 0; i<index;i++){
      aux = aux->next;
    }
    T datoFinal = aux->data;
    return datoFinal;
}

template<class T>
void List<T>::insertAtIndex(T data, int posicion){
	if(posicion > size){ 
        return;
    }
    else if(posicion < 0){
        return;
    }
    else if(posicion == 0){
        Node<T> *aux = first;
        first = new Node<T>(data, aux, aux);
        size++;
        return;
    }
    else{
        Node<T> *aux = first->next;
        Node<T> *aux2 = first;
        int index = 1;
        while(index != posicion){
            aux = aux->next;
            aux2 = aux2->next;
            index++;
        }
        aux2->next = new Node<T>(data, aux, aux2);
        size++;
        return;
    }
}

template<class T>
void List<T>::insertLast(T data){
	insertAtIndex(data, size);
}

template <class T> 
void List<T>::deleteFirst() { //last
  Node<T> *aux = this->first;
  Node<T> *newfirst = this->first->next;
  newfirst->prev = this->first->prev;
  this->first->prev->next = newfirst;

  this->first = newfirst;
  delete aux;
  size--;
  return;
}
