#include <iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;
int n;vector<int>ans;

void rank1(vector<int>& a){
    for(int i=a.size()-1;i>0;i--){
        if(a[i]>a[i-1]){
            int k=a[i];
            a[i]=a[i-1];
            a[i-1]=k;
        }
    }
}

int main(){
    cin>>n;
    ans.resize(n);
    long long ans1=0;
    for(int i=0;i<n;i++){
        cin>>ans[i];
    }
    sort(ans.begin(),ans.end(),[](int a,int b){return a>b;});
    while(ans.size()!=1){
        rank1(ans);
        int a=*(ans.end()-2),b=*(ans.end()-1);
        ans1=ans1+a+b;
        ans.pop_back();ans.pop_back();
        ans.push_back(a+b);
    }
    cout<<ans1;
}