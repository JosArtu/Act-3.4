// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#include "LoginSystem.h"

// Referencias: https://www.youtube.com/watch?v=Re417iwYM84 Lectura de archivos
// Referencias: https://www.geeksforgeeks.org/cpp/stdstringerase-in-cpp/ Uso de erase
// Referencias: https://www.youtube.com/watch?v=Rfe2Jb2JP-Y escritura de archivos
// Referencias: https://www.geeksforgeeks.org/cpp/getline-string-c/ Getline para tomar todo el input con espacios
// Complejidad: O(n log n)
LoginSystem::LoginSystem(){
    double days;
    string time, ip, reason, month;
    FileLocation = "bitacora2.txt";
    ifstream rawFile(FileLocation);
    lista = new MyLinkedList();

    while (!rawFile.eof()){
        rawFile >> month;
        rawFile >> days;
        rawFile >> time;
        rawFile >> ip; 

        getline(rawFile, reason);
        reason.erase(0, 1);

        lista->insertLast(days, time, ip, reason, month);
    }
    
    cout << "Sorting..." << endl;
    sortRequests = new SortSystem(lista);
    cout << "Sorted\n" << endl;
    delete sortRequests;
    cout << "Inserting IPs in BST..." << endl;
    searchRequests = new SearchSystem(lista);
    cout << "Finished\n" << endl;


    ofstream sortedFile("bitacoraOrdenadaIP-eq8-BST.txt");

    MyNodoLL* actualNode = lista->getAtNode(0);
    int n = lista->length();
    for (int i = 0; i < n; i++){
        sortedFile << actualNode->request->getMonth() << " ";
        sortedFile << actualNode->request->getDay() << " ";
        sortedFile << actualNode->request->getTime() << " ";
        sortedFile << actualNode->request->getIp() << " ";
        sortedFile << actualNode->request->getReason();

        if(i != n - 1){
            sortedFile << "\n";
            actualNode = actualNode->next;
        }
    }
}
//Complejidad O(n)
LoginSystem::~LoginSystem(){
    MyNodoLL* actualNode = lista->getAtNode(0);
    MyNodoLL* nextNode;
    int n = lista->length();
    for (int i = 0; i < n; i++){
        nextNode = actualNode->next;
        delete actualNode->request;
        actualNode = nextNode;
    }
    delete lista;
    delete searchRequests;
}

void LoginSystem::searchTopIPs(int n){
    this->searchRequests->searchRequests(n);
}
