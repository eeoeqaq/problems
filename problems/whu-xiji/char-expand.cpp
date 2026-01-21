#include <iostream>
using namespace std;
#include<string>
string a,b;

string expand(string a){
    string ans;
    for(int i=0;i<a.length();i++){
        if(a[i]!='-'){
            ans.push_back(a[i]);
        }else if(a[i]=='-'){
            if((i+1)<a.length() && a[i+1]>a[i-1]){
                int be = a[i-1];int ed = a[i+1];
                for(int j=be+1;j<ed;j++){
                    ans.push_back(char(j));
                }
            }else{
                ans.push_back('-');
            }
        }
    }
    return ans;
}

int main() {
    getline(cin,a);
    b = expand(a);
    cout<<b;
    //cin>>a;
    return 0;
}