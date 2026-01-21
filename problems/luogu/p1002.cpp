#include<iostream>
using namespace std;
int n,m,a,b;
int map[21][21]={};
int dx[]={2,1,1,2,-2,-1,-1,-2,0};
int dy[]={1,2,-2,-1,1,2,-2,-1,0};
int cnt=0;
int mem[21][21]={};
bool vis[21][21]={};
int dfs(int x,int y){
    if(x>n||y>m||map[x][y])return 0;
    if(x==n&&y==m){
        return 1;
    }
    
    if(vis[x][y])return mem[x][y];
    
    vis[x][y]=1;
    if(!map[x+1][y])  {
        mem[x][y]+=dfs(x+1,y);
    }
    if(!map[x][y+1])  {
        mem[x][y]+=dfs(x,y+1);
    }
    return mem[x][y];
}
int main(){
    cin>>n>>m>>a>>b;
    for(int i=0;i<9;i++){
    int nx = a + dx[i];
    int ny = b + dy[i];
    if (nx >= 0 && nx <= n && ny >= 0 && ny <= m) {
        map[nx][ny] = 1;                            
    }
}
    cnt=dfs(0,0);
    
    cout<<cnt;
}