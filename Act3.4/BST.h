#include <iostream>
#include <vector>

using namespace std;

#include "NodeTree.h"
//El BST Arbol BST se puede utilizar el recorrido en orden para recuperar los datos ordenados, al igual que la busqueda binaria, se puede utilizar para buscar los datos en O(log n) en su mejor caso ocurre cuando la BST formada es una BST equilibrada, en su peor caso la insercción y la operación de busqueda es O(n)
class BST {
private:
  NodeTree *root;

public:
  vector<NodeTree> vectorDatos;
  vector<NodeTree> vectorAccesos;

  void insertDatos(Datos data);
  void insertDatosPrueba(Datos data);
  void insertAccesos(NodeTree node);
  void inOrderMain();
  void inOrderMainAccesos();
  void inorder(NodeTree *);
  void inOrderAccesos(NodeTree *);
  NodeTree *getRoot();
};

NodeTree *BST::getRoot() { return this->root; }

/*
void BST::insertDatos(Datos data) {
  NodeTree *aux = root;
  NodeTree *leaf = nullptr;
  NodeTree *accesos = nullptr;
  int cont = 0;
  while (aux != nullptr) {
    if (aux->getData().getRed() == data.getRed()) {
      aux->aumentarAcceso();
      data.setAccesos(aux->getAccesos());

      accesos = aux;
      return;
    }
    leaf = aux;
    if (data.getRed() < aux->getData().getRed()) {
      aux = aux->getLeft();
    } else {
      aux = aux->getRight();
    }
  }

  if (leaf == nullptr) {
    root = new NodeTree(data);
  } else {
    if (data.getRed() < leaf->getData().getRed()) {
      leaf->setLeft(new NodeTree(data));
    } else {
      leaf->setRight(new NodeTree(data));
    }
  }
  if (accesos == nullptr) {
    root = new NodeTree(data);
  } else {
    if (data.getAccesos() < leaf->getData().getAccesos()) {
      accesos->setLeft(new NodeTree(data));
    } else {
      accesos->setRight(new NodeTree(data));
    }
  }
}*/

void BST::insertDatosPrueba(Datos data) {
  NodeTree *aux = root;
  NodeTree *leaf = nullptr;

  while (aux != nullptr) {
    if (aux->getData().getRed() == data.getRed()) {
      aux->aumentarAcceso();
      return;
    }
    leaf = aux;
    if (data.getRed() < aux->getData().getRed()) {
      aux = aux->getLeft();
    } else {
      aux = aux->getRight();
    }
  }

  if (leaf == nullptr) {
    root = new NodeTree(data);
  } else {
    if (data.getRed() < leaf->getData().getRed()) {
      leaf->setLeft(new NodeTree(data));
    } else {
      leaf->setRight(new NodeTree(data));
    }
  }
}

void BST::insertAccesos(NodeTree node) {
  NodeTree *aux = root;
  NodeTree *leaf = nullptr;

  while (aux != nullptr) {

    leaf = aux;
    //aux = (node.getAccesos() < aux->getAccesos()) ? aux->getLeft(): aux->getRight();
    if (node.getAccesos() < aux->getAccesos()) {
      aux = aux->getLeft();
    } else {
      aux = aux->getRight();
    }
  }
  
  if (leaf == nullptr) {
    root = new NodeTree(node.getData(), node.getData().getAccesos());
  } else {
    //(node.getAccesos() < leaf->getAccesos() ) ? leaf->setLeft(new
    //NodeTree(node.getData(), node.getAccesos())) : leaf->setRight(new
    //NodeTree(node.getData(), node.getAccesos()));
    if (node.getAccesos() < leaf->getAccesos()) {
      leaf->setLeft(new NodeTree(node.getData(), node.getData().getAccesos()));
    } else {
      leaf->setRight(new NodeTree(node.getData(), node.getData().getAccesos()));
    }
  }
}

void BST::inOrderMain() { inorder(root); }

void BST::inorder(NodeTree *auxRoot) {
  if (auxRoot != nullptr) {
    // return;
    inorder(auxRoot->getLeft());
    NodeTree datoVector = *auxRoot;
    vectorDatos.push_back(datoVector);
    // cout << datoVector.getData().getRed() << "\t";
    // cout << datoVector.getAccesos() << "\t";
    inorder(auxRoot->getRight());
  }
}

void BST::inOrderMainAccesos() { inOrderAccesos(root); }

void BST::inOrderAccesos(NodeTree *auxRoot) {
  if (auxRoot != nullptr) {
    // return;
    inOrderAccesos(auxRoot->getLeft());
    NodeTree datoVector = *auxRoot;
    vectorAccesos.push_back(datoVector);
    cout << datoVector.getData().getRed() << "\t";
    cout << datoVector.getAccesos() << "\t";
    inOrderAccesos(auxRoot->getRight());
  }
}