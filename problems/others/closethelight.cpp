//熄灯问题   
#include <iostream>
using namespace std;
int mat[10][10]={0};
int op[10][10]={0};   


int getstate(int x ,int y){
    if((mat[x][y]+op[x][y]+op[x-1][y]+op[x][y-1]+op[x][y+1]+op[x+1][y])%2==0)
        return 0;
    else
        return 1;
}

void read(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=6;j++){
            cin>>mat[i][j];
        }
    }
}

void print(){
    for (int i=1;i<=5;i++){
        for(int j=1;j<=6;j++){
            cout<<op[i][j]<<" ";
        }
        cout<<endl;
    }   
}

void firstrow(int n){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=6;j++){
            op[i][j]=0;
    }}
    int cnt=1;
    while(n){
        op[1][cnt]=n&1;
        n>>=1;
        cnt++;
    }
    for(int i=2;i<=5;i++){
        for(int j=1;j<=6;j++){
            if(getstate(i-1,j)){
                op[i][j]=1;
            }else 
            op[i][j]=0;
        }
    }
}

bool check(){
    for(int i=1;i<=6;i++){
        if (getstate(5,i)==1)
        {
            return false;
        }
       
    }
    return true;
}


int main(){
    read();
    for(int i=0;i<64;i++){
        firstrow(i);
        if(check()){
            print();
            break;
        }
    }
}