//
// Created by oscar on 28/08/2021.
//

#include "Gestion.h"


Gestion::Gestion() {

    Gestion::facture = new ListDouble<Factura>();
    Gestion::facturesorted = new ListDouble<Factura>();
}

void Gestion::GestionarEntradaDatos() {


    ValidaridFactura();

    cout << "Digite el Nombre del Producto: " << endl;
    getline(cin, name);


    cout << "Digite la descripcion del producto: " << endl;
    getline(cin, description);


    ValidarAmountFactura();

    ValidarValueFactura();


}

int Gestion::ValidarDoubleFactura(char numero[]) {


    for (int i = 0; i < strlen(numero); i++) {
        if (numero[i] == ',') {

            return 1;
        }
        if (!(isdigit(numero[i]))) {
            cout << "INGRESA SOLO NUMEROS" << endl;

            return 0;
        }

    }
    return 1;

}


int Gestion::ValidarEntero(char numero[]) {


    int i;
    for (i = 0; i < strlen(numero); i++) {
        if (!(isdigit(numero[i]))) {
            cout << "INGRESA SOLO NUMEROS" << endl;

            return 0;
        }
    }
    return 1;

}

int Gestion::ValidarAmountFactura() {

    do {
        cout << "Digite la cantidad del producto: " << endl;
        gets(numero);
        validar = ValidarEntero(numero);

    } while (validar == 0);

    numerovalido = atoi(numero);
    amount = numerovalido;

    return amount;

}

int Gestion::ValidaridFactura() {

    do {
        cout << "Digite el numero ID de la factura: " << endl;
        gets(numero);
        validar = ValidarEntero(numero);

    } while (validar == 0);

    numerovalido = atoi(numero);
    id = numerovalido;

    return id;
}

double Gestion::ValidarValueFactura() {


    do {
        cout << "Digite el valor del Producto: " << endl;
        gets(numero);
        validar = ValidarDoubleFactura(numero);

    } while (validar == 0);

    numerovalido = atof(numero);
    value = numerovalido;

    return value;

}

void Gestion::addFirst() {


    GestionarEntradaDatos();
    if (facture->findNode(id) != NULL) {
        cout << "El objeto ya existe , porfavor ingrese otro ID" << endl;

    } else {

        facture->addNodeFirst(Factura(id, name, description, amount, value));
    }

}

void Gestion::addSorted() {


    GestionarEntradaDatos();
    if (facturesorted->findNode(id) != NULL) {
        cout << "El objeto ya existe , porfavor ingrese otro ID" << endl;

    } else {

        facturesorted->addNodeSorted(Factura(id, name, description, amount, value));
    }

}

void Gestion::addLast() {

    GestionarEntradaDatos();
    if (facture->findNode(id) != NULL) {
        cout << "El objeto ya existe , porfavor ingrese otro ID" << endl;

    } else {

        facture->addNodeLast(Factura(id, name, description, amount, value));
    }

}


void Gestion::getListTrue() {

    if (facture->getSize() != 0) {

        for (Factura factura: facture->getListDouble(true)) {
            cout << factura << endl;
        }
    } else {

        cout << "No se ha encontrado ningun Objeto!" << endl;
    }

}

void Gestion::getObject() {

    if (facture->getSize() != 0) {

            cout<<"Mostrar Objeto en el index: "<<endl;
            Index();

            if (index>facture->getSize()){

                cout<<"Error index fuera del tamaño de la lista!!"<<endl;

            } else{

                Factura *getobject = facture->getObject(index);

                cout<<"El elemento en la posicion "<< index<< " es: "<<*getobject<<endl;

            }


    } else {

        cout << "La lista esta vacia!!" << endl;
    }

}

void Gestion::getSize() {
    cout<<"El tamaño de la lista doblemente enlazada es: "<<facture->getSize()<<endl;
}


void Gestion::getListTrueSorted() {

    if (facturesorted->getSize() != 0) {

        for (Factura facturasortedtrue: facturesorted->getListDouble(true)) {
            cout << facturasortedtrue << endl;
        }
    } else {

        cout << "No se ha encontrado ningun Objeto!" << endl;
    }

}

void Gestion::getListFalse() {

    if (facture->getSize() != 0) {

        for (Factura factura: facture->getListDouble(false)) {
            cout << factura << endl;
        }
    } else {

        cout << "No se ha encontrado ningun Objeto!" << endl;
    }

}

void Gestion::getListFalseSorted() {

    if (facturesorted->getSize() != 0) {

        for (Factura facturasortedfalse: facturesorted->getListDouble(false)) {
            cout << facturasortedfalse << endl;
        }
    } else {

        cout << "No se ha encontrado ningun Objeto!" << endl;
    }

}


void Gestion::ShowFirstElement() {

    if (facture->getSize() != 0) {

        cout << facture->getFirst() << endl;

    } else {

        cout << "La lista esta vacia!!" << endl;
    }

}

void Gestion::ShowFirstElementSorted() {

    if (facturesorted->getSize() != 0) {

        cout << facturesorted->getFirst() << endl;

    } else {

        cout << "La lista Ordenada esta vacia!!" << endl;
    }

}

void Gestion::ShowLastElement() {

    if (facture->getSize() != 0) {

        cout << facture->getLast() << endl;
    } else {

        cout << "La lista esta vacia!!" << endl;
    }


}

void Gestion::ShowLastElementSorted() {

    if (facturesorted->getSize() != 0) {

        cout << facturesorted->getLast() << endl;
    } else {

        cout << "La lista Ordenada esta vacia!!" << endl;
    }


}

void Gestion::addAfter() {

    GestionarEntradaDatos();
    if (facture->findNode(id) != NULL) {
        cout << "El objeto ya existe , porfavor ingrese otro ID" << endl;

    } else {
        cout << "Añadir despues de: (Porfavor ingrese el ID del objeto)" << endl;
        findID();
        if (facture->findNode(find) != NULL) {

            facture->addNodeAfterTo(facture->findNode(find), Factura(id, name, description, amount, value));
        } else {

            cout << "El objeto no ha sido encontrado!!" << endl;
        }

    }

}

int Gestion::findID() {

    do {
        gets(numero);
        validar = ValidarEntero(numero);

    } while (validar == 0);

    numerovalido = atoi(numero);
    find = numerovalido;

    return find;

}

int Gestion::Index() {

    do {
        gets(numero);
        validar = ValidarEntero(numero);

    } while (validar == 0);

    numerovalido = atoi(numero);
    index= numerovalido;

    return find;

}

void Gestion::addBefore() {

    GestionarEntradaDatos();
    if (facture->findNode(id) != NULL) {
        cout << "El objeto ya existe , porfavor ingrese otro ID" << endl;

    } else {
        cout << "Añadir antes de: (Porfavor ingrese el ID del objeto) " << endl;
        findID();
        if (facture->findNode(find) != NULL) {

            facture->addNodeBeforeTo(facture->findNode(find), Factura(id, name, description, amount, value));
        } else {

            cout << "El objeto no ha sido encontrado!!" << endl;
        }

    }

}

void Gestion::findObject() {

    cout << "Digite el id del objeto que desea buscar: " << endl;
    findID();
    Factura *findinfo = facture->findInfo(find);
    if (findinfo != NULL) {

        cout << *findinfo << endl;

    } else {

        cout << "La informacion del ID indicado no fue encontrado!!" << endl;
    }

}

void Gestion::findObjectSorted() {

    cout << "Digite el id del objeto que desea buscar: " << endl;
    findID();
    Factura *findinfos = facturesorted->findInfo(find);
    if (findinfos != NULL) {

        cout << *findinfos << endl;

    } else {

        cout << "La informacion del ID indicado no fue encontrado!!" << endl;
    }

}


void Gestion::deleteObject() {

    cout << "Digite el ID del nodo a eliminar: " << endl;
    findID();
    if (facture->findNode(find) != NULL) {
        cout << "Nodo a eliminar: " << facture->deleteNode(facture->findNode(find)) << endl;
    } else {

        cout << "No ha sido encontrado el objeto!" << endl;
    }

}

void Gestion::deleteObjectSorted() {

    cout << "Digite el ID del nodo a eliminar: " << endl;
    findID();
    if (facturesorted->findNode(find) != NULL) {
        cout << "Nodo a eliminar: " << facturesorted->deleteNode(facturesorted->findNode(find)) << endl;
    } else {

        cout << "No ha sido encontrado el objeto!" << endl;
    }

}


void Gestion::DestroyListSorted() {

    if (facturesorted->getSize() != 0) {

        for (Factura facturas:facturesorted->getList()) {
            facturesorted->deleteNode(facturesorted->findNode(facturas.getId()));

        }
        cout << "La lista esta vacia ??: " << facturesorted->isEmpty() << endl;

    } else {

        cout << "No se encontraron Objetos para eliminar!" << endl;

    }


}


Gestion::~Gestion() {

}








