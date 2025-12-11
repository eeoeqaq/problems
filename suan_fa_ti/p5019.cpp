#include <iostream>
using namespace std;
#include<vector>
vector<int>num;
int n,ans;
int main() {
    cin>>n;
    num.resize(n);
    for(int &x:num){
        cin>>x;
    }
    ans+=num[0];
    for(int i=0;i<n-1;i++){
        if(num[i]<num[i+1]){
            ans+=(num[i+1]-num[i]);
        }
    }
    cout<<ans;
    return 0;
}