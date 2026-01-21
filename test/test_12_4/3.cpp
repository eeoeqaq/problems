#include <iostream>
using namespace std;

int t;
void printrec(int k){
    for(int i=1;i<=k;i++){
        for(int j=1;j<=k-i;j++){
        cout<<" ";
        }
        for(int j=1;j<=2*i-1;j++){
        cout<<"*";
        }   
        cout<<endl;
    }
}

void printji(int m,int n){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void printti(int m,int n){
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m-i;j++){
            cout<<" ";
        }
        for(int j=1;j<=n;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
int main() {
    cin>>t;
    char s;int a,b;
    for(int i=0;i<t;i++){
        cin>>s>>a>>b;
        if(s=='a'){
            printrec(a);
        }else if(s=='b'){
            printji(a,b);
        }else{
            printti(a,b);
        }
    }
    return 0;
}