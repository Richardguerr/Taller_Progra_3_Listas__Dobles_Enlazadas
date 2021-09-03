//
// Created by oscar on 13/08/2021.
//

#ifndef LISTASDOBLES_NODE_H
#define LISTASDOBLES_NODE_H

#include <cstdlib>


template<class T>
class ListDouble;

template<class T>

class Node {
    friend class ListDouble<T>;

public:
    Node();

    Node(T);

    T getInfo();

    Node<T> *getNext();

    void setNext(Node<T> *next);

    virtual ~Node();


private:
    T info;
    Node<T> *next;
    Node<T> *previous;


};

template<class T>
Node<T>::Node() {
    next = NULL;
    previous = NULL;

}

template<class T>
Node<T>::Node(T info) {
    Node::info = info;
    next = NULL;
    previous = NULL;

}

template<class T>
Node<T> *Node<T>::getNext() {
    return next;
}

template<class T>
void Node<T>::setNext(Node<T> *next) {
    Node::next = next;
}

template<class T>
Node<T>::~Node() {

}

template<class T>
T Node<T>::getInfo() {
    return info;
}


#endif //LISTASDOBLES_NODE_H
