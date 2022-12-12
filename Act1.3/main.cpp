//Rodrigo Llaguno
//Cambios a Situacion Problema

#include <iostream>
using namespace std;
#include <math.h>
#include <string.h>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>

#include "Datos.h"

int conversionFecha( string mes){
  map<string, int> tot{
    { "Jan", 1 },
    { "Feb", 2 },
    { "Mar", 3 },
    { "Apr", 4 },
    { "May", 5 },
    { "Jun", 6 },
    { "Jul", 7 },
    { "Aug", 8 },
    { "Sep", 9 },
    { "Oct", 10 },
    { "Nov", 11 },
    { "Dec", 12 }
  };
  const auto x = tot.find(mes);
  if( x != tot.cend()){
    return x->second;
  }        
  return -1;
}

int conversionFechaDias( string mes, int dia ){
  map<string, int> tot{
    { "Jan", 0 },
    { "Feb", 31 },
    { "Mar", 59 },
    { "Apr", 90 },
    { "May", 120 },
    { "Jun", 151 },
    { "Jul", 181 },
    { "Aug", 212 },
    { "Sep", 243 },
    { "Oct", 273 },
    { "Nov", 304 },
    { "Dec", 334 }
  };
  const auto x = tot.find(mes);
  if( x != tot.cend()){
    return x->second+dia;
  }        
  return -1;
}

int conversionTiempoTotal(string hora){
  int h, m, s= 0, total;
  string time = hora;

  if (sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s) >= 2){
    total = (h*3600) + (m*60) + s;
  }
  return total;
}

void escribe(vector<Datos> data, int indexInicial, int indexFinal ){
    cout << "Entro a escribe" << endl;
    ofstream Archivo;
    Archivo.open("bitacoraOrdenada.txt");
    for(int i = indexInicial; i < indexFinal; i++){ //Modificar estos valores
        Archivo << data[i].getMesS() << " " << data[i].getDia() <<
        " " << data[i].getHora() <<  " " <<data[i].getIp() <<
        " " << data[i].getMensaje() << endl;
    }
    Archivo.close();
}

void merge(vector<Datos> &vI, vector<Datos> &vR, vector<Datos> &data){
	int sizeI = vI.size();
  int sizeR = vR.size();
  //cout <<"Entro a merge"<<endl;

	int i = 0;
	int j = 0;
  int k = 0;

	while (j < sizeI && k < sizeR) {

		if (vI[j].getDiasTotal() < vR[k].getDiasTotal()) {
			data[i] = vI[j];
			j++;
    }else if(vI[j].getDiasTotal() == vR[k].getDiasTotal() && vI[j].getTiempoTotal() < vR[k].getTiempoTotal()){
      data[i] = vI[j];
      j++;
    }else {
		  data[i] = vR[k]; 
			k++;
		}
    i++;
	}

	while (j < sizeI) {
		data[i] = vI[j];
		i++;
    j++;
	}

	while (k < sizeR) {
		data[i] = vR[k];
		i++;
    k++;
	}
}

void mergeSort(vector<Datos>& data){//l = 0, r = sizeVector
	//cout << "Entro a mergeSort" << endl;
  if(data.size() <= 1) return;
  int med = data.size() / 2;
  vector<Datos> vI, vR;

    for(int i = 0; i < data.size()/2; i++){
        vI.push_back(data[i]);
    }

    for(int j = data.size()/2; j < data.size(); j++ ){
        vR.push_back(data[j]);
    }

    mergeSort(vI);
    mergeSort(vR);
    merge(vI,vR, data);
}

int seuqentialSearch(vector<Datos> data, string mes, int dia){
  cout << "Entro a Sequential" << endl;
  for(int i = 0; i < data.size(); i++){
      if(data[i].getMesS() == mes && data[i].getDia() == dia){
        return i;
      }
  }
  return -1;
}

int main(){

    Datos inicio = Datos();
    Datos fin = Datos();
    bool check = false;
    string mesInicio, mesFin;
    int diaInicio, diaFin;

    while (check == false) {
    cout << "Fecha de inicio de busqueda: " << endl;
    cout << "Mes: ";
    cin >> mesInicio;
    cout << "Dia: ";
    cin >> diaInicio;
    cout << "Fecha de fin de busqueda: " << endl;
    cout << "Mes: ";
    cin >> mesFin;
    cout << "Dia: ";
    cin >> diaFin;

    inicio.setMesS(mesInicio);
    inicio.setMesI(conversionFecha(mesInicio));
    inicio.setDia(diaInicio);
    fin.setMesS(mesFin);
    fin.setMesI(conversionFecha(mesFin));
    fin.setDia(diaFin);
    int fechaInicio = conversionFechaDias(mesInicio, diaInicio);
    int fechaFin = conversionFechaDias(mesFin, diaFin);

    if (inicio.getMesI() > fin.getMesI()) {
      cout << "Rango invalido" << endl;
    } else if(inicio.getMesI() == fin.getMesI()){
        if(inicio.getDia() > fin.getDia()){
            cout << "Rango invalido" << endl;
        }else{
          check = true;
        }
    }else if(inicio.getMesS() == "Jan" || inicio.getMesS() == "Feb" || inicio.getMesS() =="Mar" || inicio.getMesS() == "Apr" || inicio.getMesS() == "May" || inicio.getMesS() == "Nov" || inicio.getMesS() == "Dec"){
       cout << "La fecha inicial no esta dentro del rango"<< endl;
      }else if(inicio.getMesS() == "Jan" || fin.getMesS() == "Feb" || fin.getMesS() =="Mar" || fin.getMesS() == "Apr" || fin.getMesS() == "May" || fin.getMesS() == "Nov" || fin.getMesS() == "Dec"){
       cout << "La fecha final no esta dentro del rango"<< endl;
      } else{
      check = true;
    }
    }

   ifstream fileIn("bitacora.txt");
   vector<Datos> data;
   string line, word;
   string mesS, diaS, hora, ip, mensaje;
   int contador = 0, mesI, diasTotal, tiempoTotal, counter=6;

   while(getline(fileIn, line)){
    stringstream ss(line);
    ss >> mesS >> diaS >> hora >> ip >> mensaje;
    while(ss >> word){
        mensaje = mensaje + " " + word;
    }
    int dia = stoi(diaS);
    mesI = conversionFecha(mesS);
    diasTotal = conversionFechaDias(mesS, dia);
    tiempoTotal = conversionTiempoTotal(hora);
    data.push_back(Datos(mesS, mesI, dia, diasTotal, hora, tiempoTotal, ip, mensaje));
    contador++;
   }
   fileIn.close();

    mergeSort(data);

    int indexInicial = seuqentialSearch(data, inicio.getMesS(), inicio.getDia());
    int indexFinal = seuqentialSearch(data, fin.getMesS(), fin.getDia()+1);

    escribe(data, indexInicial, indexFinal);

    return 0;
}