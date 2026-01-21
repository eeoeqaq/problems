#include <iostream>
using namespace std;
#include<vector>
int re1,re2;
vector<int> a;
int n,m,bf1,num1,num2;

int func(int h){
    long long sum=0;
    for(int x:a){
        if(x>h){
            sum+=(x-h);
        }
    }
    return (sum>=m) ? 1 : -1;
}

int main() {
    cin>>n>>m;
    int max1=0;
    for(int i=0;i<n;i++){
        cin>>bf1;
        max1=(bf1>max1)?bf1:max1;
        a.push_back(bf1);
    }
    num1=0;num2=max1;
    re1=func((num1+num2)/2);
    //cout<<re1<<endl;
    while(1){
        if((num2-num1)==1){
            break;
        }else{
            if(re1==1){
                num1=(num1+num2)/2;
                //cout<<num1<<endl;
                re1=func((num1+num2)/2);
                //cout<<re1<<endl;
            }else if(re1==-1){
                num2=(num1+num2)/2;
                //cout<<num2<<endl;
                re1=func((num1+num2)/2);
                //cout<<re1<<endl;
            }
        }
    }
    cout<<num1;
    return 0;
}