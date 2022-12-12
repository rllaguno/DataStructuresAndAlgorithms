#define Node_h

#include <iostream>
using namespace std;
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

template<class T>
class Node
{	public:

		T data;			//valor almacenado
		Node<T> *next;  //puntero a next
		Node<T> *prev;	//puntero a prev

		Node(T data){	
			this->data = data;
			this->next = nullptr;
			this->prev = nullptr;
		}

		Node(T data, Node<T> *next, Node<T> *prev){
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
};