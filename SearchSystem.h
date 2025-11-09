// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#ifndef SEARCHSYSTEM_H
#define SEARCHSYSTEM_H

#include "MyBST.h"

class SearchSystem{
    private:
        MyBST* searchTree;
        MyLinkedList* bitacora;
        void printRequests(MyLinkedList* lista);
    public:
        SearchSystem(MyLinkedList* bitacora);
        ~SearchSystem();
        void searchRequests(int n);
};

#endif