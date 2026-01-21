#include<iostream>
#include<vector>
using namespace std;
int n;
vector<vector<char>> ori(n,vector<char>(n,0));
vector<vector<char>> draft(n,vector<char>(n,0));
vector<vector<char>> targ(n,vector<char>(n,0));
vector<vector<char>> filped(n,vector<char>(n,0));

vector<vector<char>> t90(const vector<vector<char>> &ori){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            draft[j][n-i-1]=ori[i][j];
        }
    }
    return draft;
}

vector<vector<char>> t180(const vector<vector<char>> &ori){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            draft[n-j-1][n-i-1]=ori[i][j];
        }
    }
    return draft;
}

vector<vector<char>> t270(const vector<vector<char>> &ori){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            draft[n-j-1][i]=ori[i][j];
        }
    }
    return draft;
}

vector<vector<char>> filp(const vector<vector<char>> &ori){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            draft[i][n-j-1]=ori[i][j];
        }
    }
    return draft;
}



int main(){
    cin>>n;
    ori.resize(n, vector<char>(n));
    targ.resize(n, vector<char>(n));
    draft.resize(n, vector<char>(n));
    filped.resize(n, vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>ori[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>targ[i][j];
        }
    }
    filped=filp(ori);
    if(t90(ori)==targ){
        cout<<1;
    }else if(t180(ori)==targ){
        cout<<2;
    }else if(t270(ori)==targ){
        cout<<3;
    }else if(filped==targ){
        cout<<4;
    }else if(t90(filp(ori))==targ||t180(filp(ori))==targ||t270(filp(ori))==targ){
        cout<<5;
    }else if(ori==targ){
        cout<<6;
    }else {
        cout<<7;
    }
}