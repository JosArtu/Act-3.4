#include "MyBST.h"

MyBST::MyBST(){
    this->root = nullptr;
    this->size = 0;
}

MyBST::~MyBST(){
    this->deleteAllRec(this->root);
}

void MyBST::deleteAllRec(MyNodeBST* current){
    if (current != nullptr){
        deleteAllRec(current->left);
        deleteAllRec(current->right);
        delete current;
    }
}

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
void MyBST::getTopAccessIPRec(MyNodeBST* current, MyLinkedList* list){
    if (list->len() > list->length() && current != nullptr){
        getTopAccessIPRec(current->right, list);
        if (list->len() > list->length()){
            list->insertLast(current->ip, current->accessNumber);
        }
        getTopAccessIPRec(current->left, list);
    }
}

MyLinkedList* MyBST::getTopAccessIP(int n){
    MyLinkedList* list = new MyLinkedList(n);
    getTopAccessIPRec(this->root, list);
    return list;
}