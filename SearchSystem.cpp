#include "SearchSystem.h"
#include <iostream>
//Complejidad: Mejor de los casos: O(log n), peor de los casos: O(n)
SearchSystem::SearchSystem(MyLinkedList* bitacora): bitacora(bitacora){
    int accessRepetitions = 1;
    int pos;
    string currentIp;
    string nextIp;
    MyNodoLL* currentNodeLL = bitacora->getAtNode(0);
    searchTree = new MyBST();

    while (currentNodeLL != nullptr){
        currentIp = currentNodeLL->request->getIp();
        pos = currentIp.find(":");
        currentIp = currentIp.erase(pos);
        if (currentNodeLL->next != nullptr)
        {
            nextIp = currentNodeLL->next->request->getIp();
            pos = nextIp.find(":");
            nextIp = nextIp.erase(pos);
        }
        else{
            nextIp = "";
        }
        if (currentIp == nextIp){
            accessRepetitions++;
        }
        else{
            searchTree->insert(accessRepetitions, currentIp);
            accessRepetitions = 1;
        }
        currentNodeLL = currentNodeLL->next;
    }
}
//Complejidad: O(1)
SearchSystem::~SearchSystem(){
    delete searchTree;
}
//Complejidad: O(n, N), donde la n es la cantidad de top IPs que se piden y  la N seria los nodos del arbol, cuando el usuario pone 
// n > N, solo va recorrer hasta N y no llenara la lista, solo pondra todos los nodos del arbol en la lista.
void SearchSystem::searchRequests(int n){
    if (n > bitacora->length()){
        n = bitacora->length();
    }
    MyLinkedList* lista = searchTree->getTopAccessIP(n);
    printRequests(lista);
}
//Complejidad: O(n)
void SearchSystem::printRequests(MyLinkedList* list){
    MyNodoLL* current;
    int lenght = list->length();

    current = list->getAtNode(0);

    for (int i = 0; i < lenght; i++){
        cout << current->ip << " " << current->accessNumber << "\n";
        current = current->next;
    }
    cout << endl;
}