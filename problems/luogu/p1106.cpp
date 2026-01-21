#include <iostream>
#include<vector>
#include<string>
using namespace std;
vector<int> num;

void dlt (vector<int> &a){
    int pos=a.size()-1;
    for(int i=0;i<a.size()-1;i++){
        if(a[i]>a[i+1]){
            pos=i;
            break;
        }
    }
    for(int i=pos;i<a.size()-1;i++){
        a[i]=a[i+1];
    }
    a.pop_back();
}

int main() {
    string bf;
    cin>>bf;
    for(char a:bf){
        num.push_back(a-'0');
    }
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        dlt(num);
    }
    int j=0;
    string ans;
    for(;j<num.size();j++){
        if(num[j]!=0){
            break;
        }
    }
    for(;j<num.size();j++){
        ans+=to_string(num[j]);
    }
    cout<<ans;
    if(ans.length()==0)cout<<"0";
    return 0;
}