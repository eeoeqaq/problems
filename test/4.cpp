#include <iostream>
#include<vector>
using namespace std;
int n;

void print(int **nx,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<nx[i][j]<<' ';
        }
        cout<<endl;
    }   
}

void Tprint(int **nx,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<nx[j][i]<<' ';
        }
        cout<<endl;
    }   
}
int main() {
    cin>>n;
    int **nx=new int *[n];
    for (int i=0;i<n;i++){
        nx[i]=new int [n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>nx[i][j];
        }
    }
    print(nx,n);
    cout<<endl;
    Tprint(nx,n);
    return 0;
}