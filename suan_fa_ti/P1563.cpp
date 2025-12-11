#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n,m;
vector <bool> posi;
vector <string> name;
int main() {
    cin>>n>>m;
    posi.resize(n);name.resize(n);
    bool temp1;
    string temp2;
    for(int i=0;i<n;i++){
        cin>>temp1>>temp2;
        posi[i]=temp1;
        name[i]=temp2;
    }
    int curr=0;bool posi1=0;int diff=0;
    for(int i=0;i<m;i++){
        cin>>posi1>>diff;
        if((posi[curr]+posi1)%2==1){
            if(curr+diff>=n)diff-=n;
            curr=curr+diff;
        }else{
            if(curr-diff<0)diff-=n;
            curr=curr-diff;
        }
    }
    cout<<name[curr];
    return 0;
}