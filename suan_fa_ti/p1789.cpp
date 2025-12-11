#include<iostream>
using namespace std;
bool map[100][100];
int n,m,k,cnt;
int dx[]={0,0,0,1,-1,1,1,-1,-1,2,-2,0,0,2,2,1,1,-1,-1,-2,-2,2,2,-2,-2};
int dy[]={0,1,-1,0,0,1,-1,1,-1,0,0,2,-2,1,-1,2,-2,2,-2,1,-1,2,-2,-2,2};
void touch(int x,int y){
    for(int i=0;i<13;i++){
        int fx=x+dx[i];int fy=y+dy[i];
        if(fx>=0&&fy>=0&&fx<n&&fy<n){
            map[fx][fy]=1;
        }
    }
}

void stone(int x,int y){
    for(int i=0;i<25;i++){
        int fx=x+dx[i];int fy=y+dy[i];
        if(fx>=0&&fy>=0&&fx<n&&fy<n){
            map[fx][fy]=1;
        }
    }

}

int main(){
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            map[i][j]=0;
        }
    }
    cin>>n>>m>>k;
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        touch(x,y);
    }
    for(int i=0;i<k;i++){
        cin>>x>>y;
        stone(x,y);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]==0){
                cnt++;
            }
        }
    }
    cout<<cnt;
}