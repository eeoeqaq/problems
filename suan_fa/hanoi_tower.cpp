#include<iostream>
using namespace std;
/*关于汉诺塔问题：
对于基础汉诺塔，最简移动方法所需次数为2^n*/

void move(char srouce,char target){
    cout<<srouce<<"-->"<<target<<endl;
}
                
void hanoi(char srouce,char mid,char target,int n){
    if(n==1){
    move(srouce,target);
    }else{
    hanoi(srouce,target,mid,n-1);
    move(srouce,target);
    hanoi(mid,srouce,target,n-1);
    }
}

int main(){
    int n;
    cin>>n;
    char a='A',b='B',c='C';
    hanoi(a,b,c,n);
    system("pause");
}