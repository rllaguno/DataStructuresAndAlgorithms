// Actividad 3.4
// Rodrigo Llaguno - A01198067
// Xóchitl Danitza Martínez Ibarra - A01541822
// Diego Francisco Chamorro Teran - A00833520
// Erick Fernando Flores García - A01571029
// Julian Rojas Soto - A01740757
// Roberto Santos Moisés - A00823311
// Andrea San Martin Vital - A00833676

#include <iostream>
using namespace std;

#include <fstream>
#include <sstream>
#include <string.h>
#include <algorithm>

#include "BST.h"
#include "Datos.h"

//Obtiene la red del ip regresando un int
int obtenerRed(string ip) {
  string p1;
  size_t pos = 0;

  string delimitador = ".";
  p1 = ip.substr(0, ip.find(delimitador));

  int total = stoi(p1);
  return total;
}

// Funcion para escribir dentro del archivo "bitacoraAccesos.txt"
void escribir(BST datos){
  ofstream Archivo; 
  Archivo.open("bitacoraAccesos.txt"); 
  for(int j = datos.vectorDatos.size()-1; j > 0; j--){
    // El "Archivo" sirve como un cout pero para imprimir dentro del .txt, ademas agarramos los valores que se imprimen con los .getData() y demas.
    Archivo << datos.vectorDatos[j].getData().getMesS() << " " << datos.vectorDatos[j].getData().getDia() << " " <<
    datos.vectorDatos[j].getData().getHora() << " " << datos.vectorDatos[j].getData().getIp() << " " << datos.vectorDatos[j].getAccesos() << " " << datos.vectorDatos[j].getData().getMensaje() << endl;
  }
}

int main() {
  //Se declaran las variables
  ifstream fileIn("bitacora.txt");
  BST bst;
  string line, word;
  string mesS, diaS, hora, ip, mensaje;
  int contador = 0, mesI, diasTotal, tiempoTotal, counter = 6, red, accesos;

  //Inserta los datos de la bitacora linea por linea al BST
  while (getline(fileIn, line)) {
    stringstream ss(line);
    ss >> mesS >> diaS >> hora >> ip >> mensaje;
    while (ss >> word) {
      mensaje = mensaje + " " + word;
    }
    int dia = stoi(diaS);
    red = obtenerRed(ip);

    bst.insertDatosPrueba(Datos(mesS, dia, hora, ip, red, mensaje, accesos));
  }
  fileIn.close();

  //Se insertan los nodos del BST a un vector donde esta ordenado por red
  bst.inOrderMain();

  //Se ordena el vector por accesos, complejidad O(n^2)
  size_t size = bst.vectorDatos.size();
  
    for (size_t i = 0; i < bst.vectorDatos.size() - 1; ++i) {
        for (size_t j = 0; j < bst.vectorDatos.size() - i - 1; ++j) {
            if (bst.vectorDatos[j].getAccesos() > bst.vectorDatos[j+1].getAccesos())
                std::swap(bst.vectorDatos.at(j), bst.vectorDatos.at(j + 1));
        }
    }

  //Se imprime las top 5 redes con mas accesos
  for(int i = bst.vectorDatos.size()-1; i > bst.vectorDatos.size()-6; i--){
    cout << "Red: " << bst.vectorDatos[i].getData().getRed() << "  Accesos: " << bst.vectorDatos[i].getAccesos() << endl;
    }

  //Se imprime a bitacoraAccesos los datos de manera ordenada por accesos 
  escribir(bst);
  
  //En esta parte del codigo es el ordenamiento del primer BST con otro BST, pero no corre ya que sale Segmentation Error. Sin embargo, todas las funciones estan completas y solamente hay un error que no pudimos encontrar
  /*
  BST bst2;
  
  for (int i = 0; i < bst.vectorDatos.size(); i++) {
    cout << "Entra [" << i << "]" << endl;
    bst2.insertAccesos(bst.vectorDatos[i]);
  }

  cout << "Entro a segundo inOrder" << endl;
  bst2.inOrderMainAccesos();

  for(int i = bst2.vectorAccesos.size(); i > bst2.vectorAccesos.size()-5; i--){
    cout << "IP: " << bst2.vectorAccesos[i].getData().getIp() << "  Accesos: " << bst2.vectorAccesos[i].getAccesos() << endl;
    }*/
  
  return 0;
}