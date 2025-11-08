#include <iostream>
#include "MyLinkedList.h"
#include "MyLinkedList.cpp"
#include "LoginSystem.h"
#include "LoginSystem.cpp"
#include "FailedRequest.h"
#include "FailedRequest.cpp"
#include "SortSystem.h"
#include "SortSystem.cpp"
#include "SearchSystem.h"
#include "SearchSystem.cpp"
#include "MyBST.h"
#include "MyBST.cpp"

using namespace std;

int main(){
    LoginSystem system1;
    int n;

    do
    {
        cout << "Top IPs (0 = terminar): ";
        cin >> n;
        system1.searchTopIPs(n);

    }
    while(n != 0);
    
    return 0;
}