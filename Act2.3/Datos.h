//Rodrigo Llaguno
//Cambio Situacion Problema

#ifndef Datos_h
#define Datos_h

#include <iostream>
using namespace std;
#include <math.h>
#include <string.h>

class Datos
{
private:
    //Atributos
    string mesS;
    int mesI;
    int dia;
    int diasTotal;
    string hora;
    int tiempoTotal;
    string ip;
    //long long ipTotal;
    string mensaje;

public:
    long long ipTotal;

    //Metodos
    Datos();
    Datos(string mesS, int mesI, int dia, int diasTotal, string hora, int tiempoTotal,  string ip, long long ipTotal, string mensaje);
    void setMesS(string mesS);
    void setMesI(int mesI);
    void setDia(int dia);
    void setDiasTotal(int diasTotal);
    void setHora(string hora);
    void setTiempoTotal(int tiempoTotal);
    void setIp(string ip);
    void setIpTotal(long long ipTotal);
    void setMensaje(string mensaje);
    string getMesS();
    int getMesI();
    int getDia();
    int getDiasTotal();
    string getHora();
    int getTiempoTotal();
    string getIp();
    long long getIpTotal();
    string getMensaje();

    string mostrarDatos();

};

Datos::Datos(){
    string mesS = " ";
    int mesI = 0;
    int dia = 0;
    int diasTotal = 0;
    string hora = " ";
    int tiempoTotal = 0;
    string ip = " ";
    long long ipTotal = 0;
    string mensaje = " ";
}

Datos::Datos(string mesS, int mesI, int dia, int diasTotal, string hora, int tiempoTotal, string ip, long long ipTotal, string mensaje){
    this->mesS = mesS;
    this->mesI = mesI;
    this->dia = dia;
    this->diasTotal = diasTotal;
    this->hora = hora;
    this->tiempoTotal = tiempoTotal;
    this->ip = ip;
    this->ipTotal = ipTotal;
    this->mensaje = mensaje;
}

void Datos::setMesS(string mesS){
    this->mesS = mesS;
}

void Datos::setMesI(int mesI){
    this->mesI = mesI;
}

void Datos::setDia(int dia){
    this->dia = dia;
}

void Datos::setDiasTotal(int diasTotal){
    this->diasTotal = diasTotal;
}

void Datos::setHora(string hora){
    this->hora = hora;
}

void Datos::setTiempoTotal(int tiempoTotal){
    this->tiempoTotal = tiempoTotal;
}

void Datos::setIp(string ip){
    this->ip = ip;
}

void Datos::setIpTotal(long long ipTotal){
    this->ipTotal = ipTotal;
}

void Datos::setMensaje(string mensaje){
    this->mensaje = mensaje;
}

string Datos::getMesS(){
    return mesS;
}

int Datos::getMesI(){
    return mesI;
}

int Datos::getDia(){
    return dia;
}

int Datos::getDiasTotal(){
    return diasTotal;
}

string Datos::getHora(){
    return hora;
}

int Datos::getTiempoTotal(){
    return tiempoTotal;
}

string Datos::getIp(){
    return ip;
}

long long Datos::getIpTotal(){
    return ipTotal;
}

string Datos::getMensaje(){
    return mensaje;
}

string Datos::mostrarDatos(){
    return mesS + " " + to_string(dia) + " " + hora + " " + ip + " " + mensaje;
    /*cout << mesS << " " << dia << " " << hora << " " 
    << ip << " " << mensaje << endl;
    return;*/
}

#endif //Datos_h//