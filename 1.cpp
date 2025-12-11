#include<iostream>
#include<string>
using namespace std;
int a[100];
int b[100];
int c[101];

void read(int *x){
    string st;
    cin>>st;
    for(int i=0;i<st.size();i++){
        x[i]=st[st.size()-i-1]-'0';
    } 
}

void sum(int *a,int *b,int *c){
    for(int i=0;i<100;i++){
        c[i]=a[i]+b[i];
    }
    for(int i=0;i<100;i++){
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
}

int main(){
    read(a);
    read(b);
    sum(a,b,c);
    int i=100;
    for(;;i--){
        if(c[i]!=0)break;
    }
    for(;i>=0;i--){
        cout<<c[i];
    }
}