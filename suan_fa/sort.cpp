#include<iostream>
#include<algorithm>
using namespace std;
int cnt=10;
int a[100],b[100];
void quicksort(){

}


int main(){ 
    for(int i=0;i<cnt;i++){
        cin>>a[i];
    }
    sort(a,a+cnt,[](int a,int b){return (a%10)>=(b%10);});
    for(int i=0;i<cnt;i++){
        cout<<a[i]<<' ';
    }
}

