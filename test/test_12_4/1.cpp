#include <iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<string>
#include<sstream>
vector<int> a;
int main() {
    int x;string str;
    getline(cin,str);
    stringstream ss(str);
    while(ss>>x){
        a.push_back(x);
    }
    getline(cin,str);
    stringstream ss2(str);
    while(ss2>>x){
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<a.size()-1;i++){
        if(a[i]==a[i+1]){
            a[i]=a[i+1]=1e9;
        }
    }
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]==1e9)continue;
        cout<<a[i]<<' ';
    }
    return 0;
}