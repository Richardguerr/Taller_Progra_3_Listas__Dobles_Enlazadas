//
// Created by oscar on 28/08/2021.
//

#include "Menu.h"

Menu::Menu() {

    op = -1;
    sort = -1;
    gestion = new Gestion();

}

void Menu::menu() {


    while (op != 14) {


        cout << "------------------------------------------------------------------------------------" << endl;
        cout << "Menu Factura Virtual\n" << "1.Añadir Primero\n" << "2.Añadir Ultimo\n" << "3.Añadir despues de\n"
             << "4.Añadir antes de\n" << "5.Encontrar Objeto\n" << "6.Borrar Objeto\n" << "7.Mostrar Lista (True)\n" << "8.Mostrar Lista (False)\n"
             << "9.Mostrar Objeto \n" <<"10.Mostrar Tamaño Lista\n"<< "11.Mostrar Head\n" << "12.Mostrar Last\n" << "13.Lista Ordenada\n" << "14.Salir" << endl;
        cout << "------------------------------------------------------------------------------------" << endl;
        ValidarOp();


        switch (op) {


            case 1:

                fflush(stdin);
                gestion->addFirst();
                cout << "------------------------------------------------------------------------------------" << endl;
                break;

            case 2:
                fflush(stdin);
                gestion->addLast();
                cout << "------------------------------------------------------------------------------------" << endl;
                break;

            case 3:
                fflush(stdin);
                gestion->addAfter();
                cout << "------------------------------------------------------------------------------------" << endl;
                break;

            case 4:
                fflush(stdin);
                gestion->addBefore();
                cout << "------------------------------------------------------------------------------------" << endl;
                break;

            case 5:
                fflush(stdin);
                gestion->findObject();
                break;

            case 6:
                fflush(stdin);
                gestion->deleteObject();
                cout << "------------------------------------------------------------------------------------" << endl;
                break;

            case 7:

                gestion->getListTrue();
                cout << "------------------------------------------------------------------------------------" << endl;
                break;
            case 8:

                gestion->getListFalse();
                cout << "------------------------------------------------------------------------------------" << endl;
                break;

            case 9:

                gestion->getObject();
                cout << "------------------------------------------------------------------------------------" << endl;
                break;

            case 10:

                gestion->getSize();
                cout << "------------------------------------------------------------------------------------" << endl;

                break;

            case 11:

                gestion->ShowFirstElement();
                cout << "------------------------------------------------------------------------------------" << endl;
                break;

            case 12:

                gestion->ShowLastElement();
                cout << "------------------------------------------------------------------------------------" << endl;
                break;

            case 13:

                while (sort != 10) {
                    cout << "------------------------------------------------------------------------------------"
                         << endl;
                    cout << "Lista Ordenada\n" << "1.Añadir\n" << "2.Mostrar Lista Ordenada (True)\n"
                         << "3.Mostrar Lista Ordenada (False)\n" << "4.Mostrar Head\n"
                         << "5.Mostrar Last\n" << "6.Encontrar Objeto\n" << "7.Destruir Objeto\n"
                         << "8.Destruir Lista\n" << "10.Salir\n";
                    cout << "------------------------------------------------------------------------------------"
                         << endl;
                    ValidarSort();

                    switch (sort) {

                        case 1:

                            fflush(stdin);
                            gestion->addSorted();
                            break;

                        case 2:

                            gestion->getListTrueSorted();
                            break;

                        case 3:

                            gestion->getListFalseSorted();
                            break;

                        case 4:
                            gestion->ShowFirstElementSorted();

                            break;

                        case 5:

                            gestion->ShowLastElementSorted();
                            break;

                        case 6:

                            fflush(stdin);
                            gestion->findObjectSorted();
                            break;
                        case 7:

                            fflush(stdin);
                            gestion->deleteObjectSorted();
                            break;

                        case 8:


                            gestion->DestroyListSorted();
                            break;

                        case 10:

                            cout << "Atras.." << endl;
                            break;
                        default:
                            cout << "Opcion no valida intente nuevamente!" << endl;
                            break;

                    }
                }

                break;

            case 14:

                cout << "El programa ha finalizado correctamente!" << endl;
                cout << "------------------------------------------------------------------------------------" << endl;

                break;

            default:
                cout << "Opcion no valida , intente nuevamente!" << endl;
                cout << "------------------------------------------------------------------------------------" << endl;
                break;
        }

    }


}

int Menu::ValidarEntero(char numero[]) {


    int i;
    for (i = 0; i < strlen(numero); i++) {
        if (!(isdigit(numero[i]))) {
            cout << "INGRESA SOLO NUMEROS" << endl;

            return 0;
        }
    }
    return 1;

}

int Menu::ValidarOp() {

    do {

        gets(numero);
        validar = ValidarEntero(numero);

    } while (validar == 0);

    int numerovalido = atoi(numero);
    op = numerovalido;

    return op;

}

int Menu::ValidarSort() {

    do {

        gets(numero);
        validar = ValidarEntero(numero);

    } while (validar == 0);

    int numerovalido = atoi(numero);
    sort = numerovalido;

    return sort;

}


Menu::~Menu() = default;


