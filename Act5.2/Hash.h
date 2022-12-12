#include <iostream>
#include <string>

using namespace std;

int hash1(int key, int N)
{	return key % N;	}

int hash2(int key)
{	return 7 - (key % 7);  }

int doubleHashing ( int key, int i, int N)
{	int value = hash1(key, N) + i * hash2(key) ;
	return value;
  }

template<class T>
class Element {
	public:
		int numKey;			//	clave numerica, en que indice esta el elemento

		string strKey;		//	clave cadena
		T value;			//	atributo al cual vamos a acceder usando la key
		bool taken = false; //	celda ocupada o no


		Element<T> ()
		{	taken = false;
            value = 0;	
			strKey = "";
		}
};

template<class T>
class Hash 
{	public:
		int colisionCounter = 0;
		int max_size = 0;
		int current_size = 0;
		int i;

		Element<T> **table ;		//	Arreglo dinamico de Elements

		Hash(int size)
		{	max_size = size;
			table = new Element<T>*[max_size];		//	crea un array de elementos

			for (i =0; i < max_size; i++)
			{	 table[i] = new Element<T>();
			}

		}

		void insert(string, T);
		bool find(string, int&);
		
};

template<class T> 
void Hash<T>::insert(string strKey, T newVal)
{	
	int raw, index, key;
	raw = int( strKey[0] );
	int found  = 0;
	colisionCounter = 0;
  
	if (current_size < max_size){	
		index = hash1(raw, max_size);
		while (found == 0 ){	
      if ( table[index]->taken == false ){	
				table[index]->strKey = strKey;
				table[index]->numKey = index;
				table[index]->value = newVal;
				table[index]->taken = true;

				current_size++;
				found = 1; 
			} else {	
        colisionCounter++;
				index = doubleHashing(raw, colisionCounter, max_size) % max_size ;

        current_size++;
			}
		}
	}	else {	
    }
}

template<class T> 
bool Hash<T>::find(string strKey, int& pos)
{	int raw = int(strKey[0]); 
	pos = raw % max_size;

	int c = 0;
	colisionCounter = 0;

	int key = pos;

	while ( c < current_size ){	
    if ( table[pos]->strKey == strKey ){	
			return true;
		} else { 	
      colisionCounter++;

			pos = doubleHashing(raw, colisionCounter, max_size) % max_size ;
		}
		c++;
	}
	return false;
}