// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include "FailedRequest.h"
using namespace std;

struct MyNodoLL{
    MyNodoLL* next;
    FailedRequest* request;
    string ip;
    int accessNumber;

    MyNodoLL(double days, string time, string ip, string reason, string month, MyNodoLL* next){
        this->request = new FailedRequest(month, days, time, ip, reason);
        this->next = next;
    }
    MyNodoLL(double days, string time, string ip, string reason, string month):MyNodoLL(days, time, ip, reason, month, nullptr){};
    MyNodoLL(FailedRequest* request):request(request){
        next = nullptr;
    }
    MyNodoLL(string ip, int accessNumber):ip(ip), accessNumber(accessNumber){
        next = nullptr;
    }
};



class MyLinkedList{
    private:
        int size, lens;
        MyNodoLL* head;
        MyNodoLL* tail;
    public:
        MyLinkedList();
        MyLinkedList(int len);
        ~MyLinkedList();
        int length();
        int len();
        MyNodoLL* getAtNode(int pos);
        FailedRequest* getAt(int pos); 
        void insertLast(double days, string time, string ip, string reason, string month);
        void insertLast(FailedRequest* request);
        void insertLast(string ip, int accessNumber);
};
#endif