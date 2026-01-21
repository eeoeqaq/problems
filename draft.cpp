#include <iostream>
using namespace std;
class a{
    static int k;
    const int asw=100;
} a1,a2,a3;
int a::k=10;
int i=100;
int main() {
    auto x=new int[5];
    for(int i :{0,1,2,3,4}){
        cout<<*(x+i)<<endl;
    }
    int *qwe=&::i;
    cout<<sizeof(qwe)<<endl;
    static int asd=19;
    int i=1;
    double a{i};
    cout<<a<<'\n';
    cout<<i<<'\n'<<::i;
    return 0;
}