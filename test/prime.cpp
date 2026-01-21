#include <iostream>
#include<cmath>
using namespace std;

bool prime(int n){
    for(int i=3;i<sqrt(n);i+=2){
        if (n%i==0)return false;
    }
    return true;
}

int main() {
    bool a=prime(998244353);
    if(a){
        cout<<"true";
    }
    else{
        cout<<"false";
    }
    return 0;
}