#include <iostream>
using namespace std;
#include<string>
char st[31];char tar;bool flag=false;
int main() {
    cin>>st>>tar;
    for(int i=0;i<31;i++){
        if(st[i]==tar){
            if(!flag){
                cout<<i;
            }else{
                cout<<' '<<i;
            }
            flag=true;
        }
    }
    if(!flag){
        cout<<"NULL";
    }
    return 0;
}