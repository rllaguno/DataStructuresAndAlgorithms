#include <iostream>
#include "Datos.h"

using namespace std;

class NodeTree 
{	
    private:
        Datos data;
        NodeTree *left;
        NodeTree *right;
        int accesos;

    public: 	
		  NodeTree(Datos data)
  		{	this->data = data;
  			this->left = nullptr;
  			this->right = nullptr;
  			this->accesos = 1;
  		}
  
      NodeTree(Datos data, int accesos)
  		{	this->data = data;
  			this->left = nullptr;
  			this->right = nullptr;
  			this->accesos = accesos;
  		}
  
          Datos getData(){
              return this->data;
          }
          NodeTree* getRight(){
              return this->right;
          }
          NodeTree* getLeft(){
              return this->left;
          }
          int getAccesos(){
              return this->accesos;
          }
          void setData(Datos data){
              this->data = data;
          }
          void setRight(NodeTree *right){
              this->right = right;
          }
          void setLeft(NodeTree *left){
              this->left = left;
          }
          void setAccesos(int accesos){
            this->accesos = accesos;
          }
          void aumentarAcceso(){
              this->accesos++;
          }
};
