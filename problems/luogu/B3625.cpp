#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;
int n,m;
bool bfs(vector<vector<char>>&map){
    queue<int>qx,qy;
    qx.push(0);qy.push(0);
    while(!qx.empty()){
        int fx=qx.front();int fy=qy.front();
        if(fx==n-1&&fy==m-1){
            return true;
        }
        qx.pop();qy.pop();
        if(fx>=n||fy>=m||fx<0||fy<0){
            continue;
        }
        if(map[fx][fy]!='#'){
           map[fx][fy]='#';
           qx.push(fx+1);qy.push(fy);
           qx.push(fx);qy.push(fy+1);
           qx.push(fx);qy.push(fy-1);
           qx.push(fx-1);qy.push(fy);  
        }
    }
    return false;
}
int main(){
    cin>>n>>m;
    vector<string>a(n); 
    for (int i = 0; i < n; i++) {
    cin >> a[i];
    }
    vector<vector<char>>map(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            map[i][j]=a[i][j];
        }
    }
    
    if(bfs(map)){
       cout<<"Yes";
    }else{
       cout<<"No";
    }

}
/*for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }*/