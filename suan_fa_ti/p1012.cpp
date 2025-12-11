#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

bool compare (string a,string b){
    string bfa=a,bfb=b;
    while(bfa[0]==bfb[0]){
        bfa=bfa.substr(1);
        bfb=bfb.substr(1);
        if(bfa.length()==0&&bfb.length()==0){
            return true;
        }else if(bfa.length()==0){
            return compare(a,bfb);
        }else if(bfb.length()==0){
            return compare(bfa,b);
        }
    }
    return bfa[0]>bfb[0];
}

int main(){
    int a;vector<string> str;
    cin>>a;
    for(int i=0;i<a;i++){
        string bf;
        cin>>bf;
        str.push_back(bf);
    }
    sort(str.begin(),str.end(),compare);

    string ans;
    for(int i=0;i<a;i++){
        ans+=str[i];
    }
    cout<<ans;
}