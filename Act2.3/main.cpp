//Evidencia2 con listas enlazadas
//Rodrigo Llaguno A01198067
//Erick Flores - A01571029
//Andrea San Martin Vital - A00833676
//Xochitl Danitza Martinez Ibarra- A01541822
//Diego Francisco Chamorro Teran - A00833520

#include <iostream>
using namespace std;
#include <math.h>
#include <string.h>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include "Datos.h"
#include "List.h"
//#include "StackList.h"

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

long long conversionIpTotal(string ip){
    string p1, p2, p3, p4, totalS;
    string zeroZero = "00";
    string zero = "0";
    size_t pos = 0;
    
    string delimitador = ".";
    p1 = ip.substr(0, ip.find(delimitador));
    ip.erase(0,p1.length() + delimitador.length());
    p2 = ip.substr(0, ip.find(delimitador));
    ip.erase(0, p2.length() + delimitador.length());
    p3 = ip.substr(0, ip.find(delimitador));
    ip.erase(0,p3.length() + delimitador.length());
    p4 = ip.substr(0, ip.find(":"));
    string ipS[4] = {p1, p2, p3, p4};

    for(int i = 0; i < 4; i++){
        if(ipS[i].length() == 3){
        }else if(ipS[i].length() == 2){
          ipS[i] = zero + ipS[i];
        }else if(ipS[i].length() == 1){
          ipS[i] = zeroZero + ipS[i];
        }
    }

    totalS = ipS[0] + ipS[1] + ipS[2] + ipS[3];
    long long total = stoll(totalS);
    return total;
}

void escribe(vector<Datos> data, int indexInicial, int indexFinal ){
    cout << "Entro a escribe" << endl;
    ofstream Archivo;
    Archivo.open("bitacoraOrdenada.txt");
    for(int i = indexInicial; i < indexFinal; i++){ //Modificar estos valores
        Archivo << data[i].getMesS() << " " << data[i].getDia() <<
        " " << data[i].getHora() <<  " " <<data[i].getIp() <<
        " " << data[i].getMensaje() << " " << data[i].getIpTotal() << endl;
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

int seuqentialSearchV(vector<Datos> data, string mes, int dia){
  cout << "Entro a Sequential" << endl;
  for(int i = 0; i < data.size(); i++){
      if(data[i].getMesS() == mes && data[i].getDia() == dia){
        return i;
      }
  }
  return -1;
}

template<class T>
void split(Node<T> *first, Node<T> **vI, Node<T> **vR){
  Node<T> *aux = first;
  Node<T> *aux2 = first->next;

  while(aux2 != NULL){
    aux2 = aux2->next;
    if(aux2 != NULL){
      aux = aux->next;
      aux2 = aux2->next;
    }
  }

  *vR = aux->next;
  aux->next = NULL;
}

template<class T>
Node<T>* mergeList(Node<T> *vI, Node<T> *vR){
  if(vI == NULL){
    return vR;
  }
  if(vR == NULL){
    return vI;
  }
  if(vI->data.ipTotal < vR->data.ipTotal){
    vI->next = mergeList(vI->next, vR);
    vI->next->prev = vI;
    vI->prev = NULL;
    return vI;
  }else{
    vR->next = mergeList(vI, vR->next);
    vR->next->prev = vR;
    vR->prev = NULL;
    return vR;
  }
}

template<class T>
void mergeSortList(Node<T> **first){
  if(*first == NULL || (*first)->next == NULL){
    return;
  }

  Node<T> *vI = *first;
  Node<T> *vR = NULL;
  split(*first, &vI, &vR);
  mergeSortList(&vI);
  mergeSortList(&vR);

  *first = mergeList(vI,vR);
}

// QuickSort utilizando pilas y listas enlazadas
// No se logro la implementacion de esta funcion ya que marcaba dos errores que no supimos como resolver aunque creemos que estaba todo correctamente implementado
/*
template<class T>
Node<T> partition(Node<T> *l, Node<T> *r){
  Node<T> *pivot;
  Node<T> *aux;
  pivot = r->next;
  Node<T> *i = NULL;
  Node<T> *j = l;
  for(j; j < r; j++){
    if(j->data->ipTotal <= pivot->data->ipTotal){
      if(i == NULL){
        i = l;
      } else{
        i = i->next;
      }
      aux = i; // Intercambiar valores
      i = j;
      j = aux;
    }
    j = j->next;
  }
  if(i == NULL){
    i = l;
  } else{
    i = i->next;
  }  
  aux = i; //intercambiar valores de ip de cada nodo
  i = pivot;
  pivot = aux;
  return i;
}

template<class T>
void quickSort(Node<T> *L, Node<T> *R){
  L = L->prev;
  R = R->next;
  StackList<Datos> *stack =  new StackList<Datos>(-1);
  Node<T> *pivot;

  stack->push(L);
  stack->push(R);
  while(stack->isEmpty() != 1){
    R = stack->pop();
    L = stack->pop();
    pivot = partition(L,R);
    if(L != pivot->next && L!=pivot){
      stack->push(L);
      stack->push(pivot->prev);
    }
    if(R != pivot->prev && R != pivot){
      stack->push(pivot->next);
      stack->push(R);
    }
  }
}
*/

int main(){
    int op;
    cout << "1. Ordenar por Fecha \n2. Ordenar por IP" << endl;
    cin >> op;

    switch(op){

      case 1:{ //Ordena por fecha utilizando vectores
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
          long long ipTotal = conversionIpTotal(ip);
          data.push_back(Datos(mesS, mesI, dia, diasTotal, hora, tiempoTotal, ip, ipTotal, mensaje));
          contador++;
        }
        fileIn.close();

        mergeSort(data);

        int indexInicial = seuqentialSearchV(data, inicio.getMesS(), inicio.getDia());
        int indexFinal = seuqentialSearchV(data, fin.getMesS(), fin.getDia()+1);

        escribe(data, indexInicial, indexFinal);
        break;
      }

      case 2:{ //Ordena por IP utilizando listas enlazadas dobles 
        Datos inicio = Datos();
        Datos fin = Datos();
        bool check = false;
        string ipInicio, ipFin;

        while (check == false) {
        cout << "IP de inicio de busqueda (Ej. 342.23.875.3:4565): " << endl;
        cin >> ipInicio; //200.432.345.1:0432
        cout << "IP de fin de busqueda (Ej. 412.432.456.21:0432): " << endl;
        cin >> ipFin; //412.432.456.21:0432

        inicio.setIp(ipInicio);
        inicio.setIpTotal(conversionIpTotal(ipInicio));
        fin.setIp(ipFin);
        fin.setIpTotal(conversionIpTotal(ipFin));

        if (inicio.getIpTotal() > fin.getIpTotal()) {
          cout << "Rango invalido" << endl;
        }else{
          check = true;
        }
        }

        ifstream fileIn("bitacora.txt");
        List<Datos> data; //Lista enlazada doble
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
          long long ipTotal = conversionIpTotal(ip);
          data.insertLast(Datos(mesS, mesI, dia, diasTotal, hora, tiempoTotal, ip, ipTotal, mensaje));
          contador++;
        }
        fileIn.close();

        cout<< "Entro a merge" << endl;
        mergeSortList(&data.first);
        
        cout << "Entro a escribe" << endl;
        ofstream Archivo;
        Archivo.open("bitacoraOrdenada.txt");
        for(int i = 0; i < contador; i++){
          Datos aux = data.find(i);
          if(inicio.ipTotal < aux.ipTotal && aux.ipTotal < fin.ipTotal){
            Archivo << data.find(i).mostrarDatos() << endl;
          }
        }
        Archivo.close();
        break;
      }

      default:
        cout << "Opcion no disponible" << endl;
    }

  return 0;
}