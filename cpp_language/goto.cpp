#include<iostream>
#include<vector>
using namespace std;

void a(int k){
    d:
    printf("%d",k);
}

int main(){
    a:
    b:
    goto c;
    //goto d;
    {
        c:
        cout<<"c";
    }
    system("pause");

}