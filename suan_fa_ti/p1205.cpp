#include<iostream>
#include<vector>
using namespace std;
int n;

vector<vector<char>> t90(const vector<vector<char>> &ori,vector<vector<char>> &draft){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            draft[j][n-i-1]=ori[i][j];
        }
    }
    return draft;
}

vector<vector<char>> t180(const vector<vector<char>> &ori,vector<vector<char>> &draft){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            draft[n-i-1][n-j-1]=ori[i][j];
        }
    }
    return draft;
}

vector<vector<char>> t270(const vector<vector<char>> &ori,vector<vector<char>> &draft){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            draft[n-j-1][i]=ori[i][j];
        }
    }
    return draft;
}

vector<vector<char>> filp(vector<vector<char>> &ori,vector<vector<char>> &draft){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            draft[i][n-j-1]=ori[i][j];
        }
    }
    return draft;
}



int main(){
    cin>>n;
    vector<vector<char>> ori(n,vector<char>(n,0));
    vector<vector<char>> draft1(n,vector<char>(n,0));
    vector<vector<char>> draft2(n,vector<char>(n,0));
    vector<vector<char>> targ(n,vector<char>(n,0));
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
    if(t90(ori,draft1)==targ){
        cout<<1;
        return 0;
    }else if(t180(ori,draft1)==targ){
        cout<<2;
         return 0;
    }else if(t270(ori,draft1)==targ){
        cout<<3;
         return 0;
    }else if(filp(ori,draft1)==targ){
        cout<<4;
         return 0;
    }else if(t90(filp(ori,draft1),draft2)==targ||t180(filp(ori,draft1),draft2)==targ||t270(filp(ori,draft1),draft2)==targ){
        cout<<5;
         return 0;
    }else if(ori==targ){
        cout<<6;
         return 0;
    }else {
        cout<<7;
         return 0;
    }
}