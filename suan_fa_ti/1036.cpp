#include<cmath>
#include<iostream>
using namespace std;
int n,k;int ans=0;
int a[20];

bool is_prime(int n){
    if(n==2){
        return 1;
    }
    if(n==1){
        return 0;
    }
    if(n%2==0){
        return 0;
    }
    for(int i=3;i<=sqrt(n);i+=2){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

void recur(int u,int sum,int v){
    if(u>=n){
        if(is_prime(sum)&&v==k){
            ans++;
        }
        return;
    }
    /*if(u>=n){
        if(is_prime(sum)&&v==k){
            ans++;
        }
        return;
    }*/
    recur(u+1,sum+a[u],v+1);
    recur(u+1,sum,v);
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
     recur(0,0,0);
     cout<<ans;
}