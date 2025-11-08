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