#include<iostream>
#include<vector>
using namespace std;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lcm(int x,int y){return x*y/gcd(x,y);}


const int cnt=20;
bool map1[cnt];
void aishishai(){
    for (int i=2;i<cnt;i++){
        if(map1[i])continue;
        for(int j=i+i;j<cnt;j+=i){
            map1[j]=1;
        }
    }   
}

bool map2[cnt];
vector<int> prim;
void xianxingshai(){
    for(int i=2;i<cnt;i++){
        if (!map2[i]){prim.push_back(i);}
        for(int p:prim){
            if(i*p>=cnt)break;
            map2[i*p]=1;
            if(i%p==0)break;
        }
    }
}

int main(){
    aishishai();
    for(int i=2;i<cnt;i++){
        if (!map1[i])cout<<i<<" ";
    }
}