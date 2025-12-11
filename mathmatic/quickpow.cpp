#include <iostream>
using namespace std;

long long quickpow(int base, int rank){
    long long ans=1;
    long long d=base;
    while(rank){
        if(rank%2==1){ans*=d;}
        d=d*d;
        rank>>=1;
    }
    return ans;
}

int main() {
    cout<<quickpow(9,19);
    return 0;
}