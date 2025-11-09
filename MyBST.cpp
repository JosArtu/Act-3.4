#include "MyBST.h"

//Complejidad: O(1)
MyBST::MyBST(){
    this->root = nullptr;
    this->size = 0;
}
//Complejidad: O(n)
MyBST::~MyBST(){
    this->deleteAllRec(this->root);
}
//Complejdiad: O(n) porque visita todos los nodos
void MyBST::deleteAllRec(MyNodeBST* current){
    if (current != nullptr){
        deleteAllRec(current->left);
        deleteAllRec(current->right);
        delete current;
    }
}
//Complejidad: Mejor de los casos: O(log n), peor de los casos: O(n)
void MyBST::insert(int accessNumber, string ip){
    if (this->size == 0){
        this->root = new MyNodeBST(accessNumber, ip);
        this->size++;
        return;
    }
    
    MyNodeBST* current = this->root;
    
    while(current != nullptr){
        if(accessNumber >= current->accessNumber){
            if (current->right == nullptr){
                current->right = new MyNodeBST(accessNumber, ip);
                this->size++;
                return;
            }
            current = current->right;
        }
        else{
            if(current->left == nullptr){
                current->left = new MyNodeBST(accessNumber, ip);
                this->size++;
                return;
            }
            current = current->left;
        }
    }
}
//Complejidad: O(n, N)
void MyBST::getTopAccessIPRec(MyNodeBST* current, MyLinkedList* list){
    if (list->len() > list->length() && current != nullptr){
        getTopAccessIPRec(current->right, list);
        if (list->len() > list->length()){
            list->insertLast(current->ip, current->accessNumber);
        }
        getTopAccessIPRec(current->left, list);
    }
}
//Complejidad: O(n, N), donde la n es la cantidad de top IPs que se piden y  la N seria los nodos del arbol, cuando el usuario pone 
// n > N, solo va recorrer hasta N y no llenara la lista, solo pondra todos los nodos del arbol en la lista.
MyLinkedList* MyBST::getTopAccessIP(int n){
    MyLinkedList* list = new MyLinkedList(n);
    getTopAccessIPRec(this->root, list);
    return list;
}