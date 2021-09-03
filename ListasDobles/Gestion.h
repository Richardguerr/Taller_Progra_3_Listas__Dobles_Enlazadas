//
// Created by oscar on 28/08/2021.
//

#ifndef LISTASDOBLES_GESTION_H
#define LISTASDOBLES_GESTION_H

#include "Factura.h"
#include "LinkedDoubles.cpp"
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

class Gestion {

public:
    Gestion();

    int findID();

    int Index();

    void GestionarEntradaDatos();

    void addSorted();

    void addFirst();

    void addLast();

    int ValidarEntero(char []);

    int ValidarDoubleFactura(char []);

    int ValidaridFactura();

    int ValidarAmountFactura();

    double ValidarValueFactura();

    void getListTrue();

    void getObject();

    void getSize();

    void getListTrueSorted();

    void getListFalse();

    void getListFalseSorted();

    void ShowFirstElement();

    void ShowFirstElementSorted();

    void ShowLastElement();

    void ShowLastElementSorted();

    void addAfter();

    void addBefore();

    void findObject();

    void findObjectSorted();

    void deleteObject();

    void deleteObjectSorted();

    void DestroyListSorted();


    virtual ~Gestion();


private:
    int id, amount, find,index;
    string name, description;
    char numero[20];
    int validar;
    int numerovalido;
    double value;
    ListDouble<Factura> *facture;
    ListDouble<Factura> *facturesorted;


};

#endif //LISTASDOBLES_GESTION_H
