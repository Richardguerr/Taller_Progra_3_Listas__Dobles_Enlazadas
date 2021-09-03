//
// Created by oscar on 28/08/2021.
//

#ifndef LISTASDOBLES_MENU_H
#define LISTASDOBLES_MENU_H

#include "Gestion.h"

class Menu {

public:
    Menu();

    void menu();

    int ValidarEntero(char []);

    int ValidarOp();

    int ValidarSort();

    virtual ~Menu();

private:
    int op, validar, sort;
    char numero[20];

    Gestion *gestion;


};

#endif //LISTASDOBLES_MENU_H
