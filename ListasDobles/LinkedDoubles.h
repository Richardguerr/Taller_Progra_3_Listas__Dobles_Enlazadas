//
// Created by oscar on 28/08/2021.
//

#ifndef LISTASDOBLES_LINKEDDOUBLES_H
#define LISTASDOBLES_LINKEDDOUBLES_H

#include <vector>
#include <string>
#include "Node.h"

template<class T>
class ListDouble {
public:
    ListDouble();

    bool isEmpty();

    void addNodeFirst(T);

    void addNodeLast(T);

    Node<T> *findNode(int id);

    T *findInfo(int id);

    void addNodeBeforeTo(Node<T> *node, T info);

    void addNodeAfterTo(Node<T> *node, T info);

    void addNodeSorted(T);

    std::vector<T> getList();

    std::vector<T> getListDouble(bool);

    T deleteNode(Node<T> *);

    int getSize();

    T *getObject(int);

    T getFirst();

    T getLast();

    virtual ~ListDouble();


private:
    Node<T> *head;
    Node<T> *last;
};

#endif //LISTASDOBLES_LINKEDDOUBLES_H
