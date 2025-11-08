// José Arturo Mitre García A00228334
// Alejandro Moctezuma Manrique A01614778
// Isaac Esaú Vega Reynaga A01647044

#include "FailedRequest.h"

// Referencias: https://www.geeksforgeeks.org/cpp/substring-in-cpp/ Uso de substr y stoi
// Referencias: https://www.geeksforgeeks.org/cpp/stdstringerase-in-cpp/ Uso de erase
// Referencias: https://www.geeksforgeeks.org/cpp/std-find-in-cpp/ Uso de find
// Complejidad O(1)
FailedRequest::FailedRequest(string month, double days, string time, string ip, string reason){
    this->month = month;
    this->days = days;
    this->time = time;
    this->ip = ip;
    this->reason = reason;
    
    string ipCopy = ip;
    int pos;

    pos = ipCopy.find(".");
    double ipNumber1 = stoi(ipCopy.substr(0,pos));
    ipCopy.erase(0,pos+1);

    pos = ipCopy.find(".");
    double ipNumber2 = stoi(ipCopy.substr(0, pos));
    ipCopy.erase(0,pos+1);

    pos = ipCopy.find(".");
    double ipNumber3 = stoi(ipCopy.substr(0, pos));
    ipCopy.erase(0,pos+1);

    pos = ipCopy.find(":");
    double ipNumber4 = stoi(ipCopy.substr(0, pos));
    ipCopy.erase(0,pos+1);


    this->ipSortValue = 0;
    this->ipSortValue += ipNumber1;  
    this->ipSortValue += ipNumber2/1000.00;
    this->ipSortValue += ipNumber3/1000000.00;
    this->ipSortValue += ipNumber4/1000000000.00;
}
//Complejidad O(1)
double FailedRequest::getDay(){
    return this->days;
}
//Complejidad O(1)
string FailedRequest::getMonth(){
    return this->month;
}
//Complejidad O(1)
string FailedRequest::getTime(){
    return this->time;
}
//Complejidad O(1)
double FailedRequest::getIpSortValue(){
    return this->ipSortValue;
}
//Complejidad O(1)
string FailedRequest::getIp(){
    return this->ip;
}
//Complejidad O(1)
string FailedRequest::getReason(){
    return this->reason;
}
