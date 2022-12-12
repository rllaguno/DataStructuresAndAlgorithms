//Act 5.2
// Rodrigo Llaguno - A01198067
// Erick Flores - A01571029
// Andrea San Martin - A00833676
// Diego Chamorro - A00833520
// Xóchitl Danitza Martínez Ibarra -A01541822
// Roberto Santos Moisés - A00823311

#include <iostream>
#include <sstream>
#include <cstring>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <vector>

#include "Hash.h"

using namespace std;

struct Attempt {
	string dirIp;
	int source;
	int target;
  vector<string> sourceIP;
  vector<string> targetIP;
};

string conversionIpSinPuerto(string ip){
    string p1;
    size_t pos = 0;
    
    string delimitador = ":";
    p1 = ip.substr(0, ip.find(delimitador));
    ip.erase(0,p1.length() + delimitador.length());

    return p1;
}

int main() 
{	
  
	Hash<int> ip2pos(13370);	//	tabla hash
	vector<Attempt> attempts(13370);
	Attempt attempt;
	attempt.source = attempt.target = 0;
	string key;

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
    int prueba = 0;
    for(int i = 0; i < N; i++){
		//Lee la direccion IP
      getline(fileIn,line);
      stringstream ss(line);
      ss>>ip1;
      ip1 = conversionIpSinPuerto(ip1);

	    //Pone informacion en el vector de intentos
  	  attempt.dirIp = ip1;
  	  attempts[i] = attempt;
  
        //Agrega direccion y posicion al mapa
  	  
  	  ip2pos.insert(ip1, i);
      /*cout << prueba << endl;
      prueba += 1;*/
    }
  
   
	int pos;
    for(int j = 0; j < M; j++){
      getline(fileIn,line);
      stringstream ss(line);
      ss >> mesS >> diaS >> hora >> ip1 >> ip2 >> mensaje;
      while (ss >> word) {
        mensaje = mensaje + " " + word; 
        }
      
      ip1 = conversionIpSinPuerto(ip1);
      ip2 = conversionIpSinPuerto(ip2);

	  //Incrementa contador origen del IP que intenta acceder
	  ip2pos.find(ip1,pos);
	  attempts[pos].source += 1;
    attempts[pos].sourceIP.push_back(ip2);

	  //Incrementa el contador destino del IP que trata de ser accedido
	  ip2pos.find(ip2,pos);
	  attempts[pos].target += 1;
    attempts[pos].targetIP.push_back(ip1);

    } 
  

    fileIn.close();

  
  string buscar;
	int iBuscar;
	cout << "IP a buscar (Ej. 36.29.138.97): " << endl;
	cin >> buscar;
	buscar = conversionIpSinPuerto(buscar);

    if(ip2pos.find(buscar, iBuscar)){
      cout << "IP: " << buscar << endl;
	    cout << "\n# Source: " << attempts[iBuscar].source << endl;
      for(int i = 0; i < attempts[iBuscar].sourceIP.size(); i++){
        cout << i << ": " << attempts[iBuscar].sourceIP[i] << endl; 
      }
	    cout << "\n# Target: " << attempts[iBuscar].target << endl; 
      for(int i = 0; i < attempts[iBuscar].targetIP.size(); i++){
        cout << i << ": " << attempts[iBuscar].targetIP[i] << endl; 
      }
    } else{
      cout << "No se encontro el IP" << endl;
    }

  // Prueba archivo de salida
  ofstream Archivo;
  Archivo.open("bitacoraHash.txt");
  
  for (int i = 0; i < 13370; i++){
    Archivo << "Ip: " << attempts[i].dirIp;
    int idirIP;

    if(ip2pos.find(attempts[i].dirIp, idirIP)){
	    Archivo << "\n# Source: " << attempts[idirIP].source << ", ";
	   Archivo << " # Target: " << attempts[idirIP].target << endl << endl;  
    }
    }
    
  Archivo.close();
  
}