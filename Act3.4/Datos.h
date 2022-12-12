#ifndef Datos_h
#define Datos_h

#include <iostream>
using namespace std;
#include <math.h>
#include <string.h>

class Datos {
private:
  // Atributos
  string mesS;
  int dia;
  string hora;
  string ip;
  string mensaje;
  int red;
  int accesos;

public:
  // Metodos
  Datos();
  Datos(string mesS, int dia, string hora, string ip, int red, string mensaje,
        int accesos);
  void setMesS(string mesS);
  void setDia(int dia);
  void setHora(string hora);
  void setIp(string ip);
  void setRed(int red);
  void setMensaje(string mensaje);
  void setAccesos(int accesos);
  string getMesS();
  int getDia();
  string getHora();
  string getIp();
  int getRed();
  string getMensaje();
  int getAccesos();

  string mostrarDatos();
};

Datos::Datos() {
  string mesS = " ";
  int dia = 0;
  string hora = " ";
  string ip = " ";
  int red = 0;
  string mensaje = " ";
  int accesos = 1;
}

Datos::Datos(string mesS, int dia, string hora, string ip, int red,
             string mensaje, int accesos) {
  this->mesS = mesS;
  this->dia = dia;
  this->hora = hora;
  this->ip = ip;
  this->red = red;
  this->mensaje = mensaje;
  this->accesos = accesos;
}

void Datos::setMesS(string mesS) { this->mesS = mesS; }

void Datos::setDia(int dia) { this->dia = dia; }

void Datos::setHora(string hora) { this->hora = hora; }

void Datos::setIp(string ip) { this->ip = ip; }

void Datos::setRed(int red) { this->red = red; }

void Datos::setMensaje(string mensaje) { this->mensaje = mensaje; }

void Datos::setAccesos(int accesos) { this->accesos = accesos; }

string Datos::getMesS() { return mesS; }

int Datos::getDia() { return dia; }

string Datos::getHora() { return hora; }

string Datos::getIp() { return ip; }

int Datos::getRed() { return red; }

string Datos::getMensaje() { return mensaje; }

int Datos::getAccesos() { return accesos; }

string Datos::mostrarDatos() {
  return mesS + " " + to_string(dia) + " " + hora + " " + ip + " " + mensaje;
  /*cout << mesS << " " << dia << " " << hora << " "
  << ip << " " << mensaje << endl;
  return;*/
}

#endif // Datos_h//