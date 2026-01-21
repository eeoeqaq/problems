#include<algorithm>
#include<string>
#include<iostream>
#include<fstream>
#include<map>
#define INPUT "encrypt.txt"
#define OUTPUT "output.txt"
using namespace std;
string a,b="abcdefghijklmnopqrstuvwxyz";
int main() {
    cin>>a;
    bool bl[a.size()];
    for(int i=0;i<a.size();i++){
        for(int j=0;j<i;j++){
            if(a[i]==a[j]){
                bl[i]==0;
            }
        }
    }
    for(int i=0;i<a.size();i++){
        for(int j=0;j<i;j++){
            if(a[i]==a[j]){
                bl[i]==0;
            }
        }
    }
    cout<<endl;
    // for(char x :b){
    string s;
    s.substr();
    // }
    return 0;
}