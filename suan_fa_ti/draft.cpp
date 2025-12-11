#include<iostream>
#include<cmath>
using namespace std;
int n;
bool map[1024][1024];

void rewrite(int a){
    int k=pow(2,a);
     for(int i=0;i<pow(2,n);i++){
        for(int j=0;j<pow(2,n);j++){
           if(i%k==0 && j%k==0) map[i][j]==0
        }
    }
    
}

int main(){
    cin>>n;
    for(int i=0;i<pow(2,n);i++){
        for(int j=0;j<pow(2,n);j++){
            map[i][j]=1;
        }
    }
    for(int i=n-1;i>=0;i--){
        rewrite(n);
    }
    for(int i=0;i<pow(2,n);i++){
        for(int j=0;j<pow(2,n);j++){
            cout<<map[i][j];
        }
    }
}


 int max1=0;
    for(int i=0;i<26;i++){
        if(cnt[i]>max1)max1=cnt[i];
    }
    for(int i=max1;i>0;i--){
        for(int j=0;j<26;j++){
            if(cnt[j]>=i){
                cout<<'*';
            }else{
                cout<<' ';
            }
        }
    }
    cout<<"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
