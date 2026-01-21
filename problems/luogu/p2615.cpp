#include<iostream>
#include<vector>
using namespace std;

int answer[41][41]={0};
int main(){
    int n;
    cin>>n;
    int r=20-n/2;int c=20;
    int first_r=r;int first_c=c-n/2;
    int last_r=r+n-1;int last_c=c+n/2;
    for(int i=1;i<=n*n;i++){
        answer[r][c]=i;
        if(r==first_r&&c!=last_c){
            r=last_r;
            c++;
        }else if(r!=first_r&&c==last_c){
            r--;
            c=first_c;
        }else if(r==first_r&&c==last_c){
            r++;
        }else if(answer[r-1][c+1]==0){
            r--;
            c++;
        }else {
            r++;
        }
        /*if(r>last_r){
            r-=n;
        }
        if(r<first_r){
            r+=n;
        }
        if(c>last_c){
            c-=n;
        }
        if(c<first_c){
            c+=n;
        }*/
    }
    for(int i=first_r;i<=last_r;i++){
        for(int j=first_c;j<=last_c;j++){
           cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
}