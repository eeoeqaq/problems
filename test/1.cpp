#include <iostream>
#include <cstring>
#include "employee.h"
using namespace std;

Employee::Employee(const char* n, const char* str, const char* ct,const char* z){
    memcpy(name,n,sizeof(name));
    memcpy(street,str,sizeof(street));
    memcpy(city,ct,sizeof(city));
    memcpy(zip,z,sizeof(zip));
}

void Employee::setName(char* n){
    memcpy(name,n,sizeof(name));
}

void Employee::display(){
    cout<<name<<' '<<street<<' '<<city<<' '<<zip<<endl;
};
