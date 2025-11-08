#ifndef MYBST_H
#define MYBST_H

#include "MyLinkedList.h"

struct MyNodeBST{
    MyNodeBST* left;
    MyNodeBST* right;
    int accessNumber;
    string ip;

    MyNodeBST(int accessNumber, string ip, MyNodeBST* left, MyNodeBST* right):accessNumber(accessNumber),ip(ip),left(left),right(right){}
    MyNodeBST(int accessNumber, string ip):MyNodeBST(accessNumber, ip, nullptr, nullptr){}
};

class MyBST{
    private:
        MyNodeBST* root;
        int size;
        void getTopAccessIPRec(MyNodeBST* current, MyLinkedList* list);
        void deleteAllRec(MyNodeBST* current);
    public:
        MyBST();
        ~MyBST();
        void insert(int accessNumber, string ip);
        MyLinkedList* getTopAccessIP(int n);
};

#endif