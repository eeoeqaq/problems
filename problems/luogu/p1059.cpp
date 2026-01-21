#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int t;vector<int> a(t);
int main(){
    cin>>t;
    a.resize(t);
    for(int &x :a){
        cin>>x;
    }
    sort(a.begin(),a.end());
    auto x=unique(a.begin(),a.end());
    cout<<x-a.begin()<<endl;
    for(int i=0;i<x-a.begin();i++){
        cout<<a[i]<<' ';
    }
}