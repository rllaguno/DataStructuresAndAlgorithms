#include <iostream>
#include <string.h>
using namespace std;

class Nodo{
  
  public:
    string ip;
    int accesos;

    Nodo() = default;
    Nodo(string IP, int ACCESOS): ip(IP), accesos(ACCESOS) {}
  
};