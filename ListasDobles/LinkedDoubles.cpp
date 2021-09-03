//
// Created by oscar on 28/08/2021.
//

#include "LinkedDoubles.h"

template<class T>
ListDouble<T>::ListDouble() {
    head = NULL;
    last = NULL;
}

template<class T>
bool ListDouble<T>::isEmpty() {
    return head == NULL && last == NULL;
}

template<class T>
void ListDouble<T>::addNodeFirst(T info) {
    Node<T> *newNode = new Node<T>(info);
    if (isEmpty()) {
        head = newNode;
        last = newNode;
    } else {
        head->previous = newNode;
        newNode->next = head;
        head = newNode;
    }
}

template<class T>
void ListDouble<T>::addNodeLast(T info) {
    Node<T> *newNode = new Node<T>(info);
    if (isEmpty()) {
        head = newNode;
        last = newNode;
    } else {
        last->next = newNode;
        newNode->previous = last;
        last = newNode;
    }
}

template<class T>
Node<T> *ListDouble<T>::findNode(int id) {

    Node<T> *aux = head;
    while (aux != NULL) {
        if (aux->info.getId() == id) {
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

template<class T>
T *ListDouble<T>::findInfo(int id) {
    Node<T> *aux = head;
    while (aux != NULL) {
        if (aux->info.getId() == id) {
            return &aux->info;

        }
        aux = aux->next;
    }
    return NULL;
}

template<class T>
void ListDouble<T>::addNodeBeforeTo(Node<T> *node, T info) {
    if (node == head) {
        addNodeFirst(info);
    } else {
        Node<T> *newNode = new Node<T>(info);
        Node<T> *previo = NULL;
        Node<T> *aux = head;
        while (aux->next != node) {
            aux = aux->next;
        }
        newNode->next = aux->next;
        previo = aux->next;
        newNode->previous = aux;
        aux->next = newNode;
        previo->previous = aux->next;
    }
}

template<class T>
void ListDouble<T>::addNodeAfterTo(Node<T> *node, T info) {
    Node<T> *newNode = new Node<T>(info);
    Node<T> *aux = head;
    while (aux != node) {
        aux = aux->next;
    }
    if (aux == last) {
        last->next = newNode;
        newNode->previous = last;
        last = newNode;
    } else {
        Node<T> *previo = NULL;
        newNode->next = aux->next;
        previo = aux->next;
        newNode->previous = aux;
        aux->next = newNode;
        previo->previous = newNode;
    }


}

template<class T>
void ListDouble<T>::addNodeSorted(T info) {

    Node<T> *newNode = new Node<T>(info);

    if (isEmpty()) {
        head = new Node<T>(info);
        last = new Node<T>(info);

    } else {
        Node<T> *act = head;
        Node<T> *las = head;
        Node<T> *ant = NULL;

        while (act != NULL && info.getId() > act->info.getId()) {

            ant = act;
            act = act->next;
        }
        if (ant == NULL) {


            head = newNode;
            if (act->info.getId() == last->info.getId()) {
                newNode->next = last;
                last->previous = newNode;

            } else {

                newNode->next = act;
                act->previous = newNode;

            }


        } else {
            if (act == NULL) {

                last = newNode;

                newNode->previous = ant;
                ant->next = newNode;

            } else {

                newNode->previous = ant;
                ant->next = newNode;

                newNode->next = act;
                act->previous = newNode;
            }

        }

    }


}

template<class T>
std::vector<T> ListDouble<T>::getList() {
    std::vector<T> output;
    Node<T> *aux = head;
    while (aux != NULL) {
        output.push_back(aux->info);
        aux = aux->next;
    }

    return output;
}

template<class T>
std::vector<T> ListDouble<T>::getListDouble(bool forward) {
    std::vector<T> out;
    Node<T> *aux = forward ? head : last;
    while (aux != NULL) {
        out.push_back(aux->info);
        aux = forward ? aux->next : aux->previous;
    }

    return out;
}

template<class T>
T ListDouble<T>::deleteNode(Node<T> *node) {

    T info = node->info;
    Node<T> *prev = NULL;


    if (node == head && node->next == NULL) {
        head = NULL;
        last = NULL;


    } else {

        if (node == head) {
            head = head->next;
            head->previous = NULL;

            //prev=head->next;
            //prev->previous=
        } else if (node == last) {
            last = last->previous;
            last->next = NULL;
        } else {
            Node<T> *aux = head;

            while (aux->next != node) {
                aux = aux->next;

            }
            aux->next = node->next;
            prev = node->next;
            prev->previous = aux;
        }
    }

    delete (node);
    return info;


}

template<class T>
int ListDouble<T>::getSize() {
    int contador = 0;

    Node<T> *aux = head;

    while (aux != NULL) {

        contador += 1;
        aux = aux->next;
    }

    return contador;
}

template<class T>
T *ListDouble<T>::getObject(int index) {


    Node<T> *aux = head;
    int i = 0;
    while (aux != NULL) {
        if (i==index){
            return &aux->info;

        }
        aux = aux->next;
        i++;
    }

    return NULL;

}

template<class T>
T ListDouble<T>::getFirst() {

    return head->info;

}

template<class T>
T ListDouble<T>::getLast() {


    return last->info;

}


template<class T>
ListDouble<T>::~ListDouble() {

}
