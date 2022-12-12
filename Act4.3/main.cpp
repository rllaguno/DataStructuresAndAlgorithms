// Evidencia 4.3 
// Rodrigo Llaguno - A01198067
// Erick Flores - A01571029
// Diego Chamorro - A00833520
// Andrea San Martin - A00833676
// Xochitl Danitza Martinez Ibarra- A01541822
// Roberto Santos Moisés - A00823311

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#include "Nodo.h"

using namespace std;

string conversionIpSinPuerto(string ip){
    string p1;
    size_t pos = 0;
    
    string delimitador = ":";
    p1 = ip.substr(0, ip.find(delimitador));
    ip.erase(0,p1.length() + delimitador.length());

    return p1;
}

template<class T>int ordenarBitacoraNodal(T* array, int N){
 T aux_elem;

 for (int i = 0; i < N - 1; i++){
     for (int j = 1; j < N; j++){
         if (array[j].accesos < array[j-1].accesos){   
             aux_elem = array[j];
             array[j] = array[j-1];
             array[j-1] = aux_elem;
         }
     }
 }
 return 0;
}

int main() {
  cout << "Cargando...\n" << endl;
  
  //Creacion de grafo
  Nodo *ipNodo = new Nodo[13370];
  string ipOrigen[91910];
  string ipDestino[91910];

  //Insertar valores de la bitacora al grafo
  ifstream fileIn("bitacora.txt");
    string line, word;
    string mesS, diaS, hora, ip1, ip2, mensaje;
    string ipN;
    string nS, mS;
    getline(fileIn, line);
    stringstream ss(line);
    ss >> nS >> mS;

    int N = stoi(nS);
    int M = stoi(mS);
    int acc = 0;

    for(int i = 0; i < N; i++){
      getline(fileIn,line);
      stringstream ss(line);
      ss>>ip1;
      ip1 = conversionIpSinPuerto(ip1);
      ipNodo[i] = Nodo(ip1,acc);
    }

    for(int j = 0; j < M; j++){
      getline(fileIn,line);
      stringstream ss(line);
      ss >> mesS >> diaS >> hora >> ip1 >> ip2 >> mensaje;
      while (ss >> word) {
        mensaje = mensaje + " " + word; 
        }
      ip1 = conversionIpSinPuerto(ip1);
      ip2 = conversionIpSinPuerto(ip2);
      ipOrigen[j] = ip1;
      ipDestino[j] = ip2;
    }
  
    fileIn.close();

    //Determinar cuantos accesos tiene cada ip
    for(int i = 0; i < N; i++){
      for(int j = 0; j < M; j++){
        if(ipNodo[i].ip == ipOrigen[j]){
          ipNodo[i].accesos += 1;
        }
      }
    }

  //Ordena el grafo
  ordenarBitacoraNodal(ipNodo,N);

  //Escribir los IP y Accesos a bitacora de accesos
  ofstream Archivo;
  Archivo.open("bitacoraNodal.txt");
  for(int i = 13369; i > 0; i--){
    Archivo << "IP: " << ipNodo[i].ip << "\tAccesos: " << ipNodo[i].accesos << endl;
  }
  Archivo.close();

  //Escribir top 5 accesos en consola
  int x = 1;
  cout << "IPs con mas accesos: " << endl;
  for(int i = 13369; i > 13364; i--){
    cout << "IP " << x << ": " << ipNodo[i].ip << "\tAccesos: " << ipNodo[i].accesos << endl;
    x += 1;
  }

  //Determinar quien es el Bootmaster
  cout << "\nIP de Posible Bootmaster: " << ipNodo[13369].ip << endl;
  
  
}