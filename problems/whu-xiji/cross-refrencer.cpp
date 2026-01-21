#include <iostream>
using namespace std;
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#define INFILE "crossin.txt"
#define OUTFILE "crossout.txt"
map<int,vector<string>> strmap;map<string,vector<int>>linemap;

string check(string& a){
    if((*(a.end()-1)=='.')||(*(a.end()-1)==',')||(*(a.end()-1)==';')||(*(a.end()-1)=='?')
    ||(*(a.end()-1)==':')){
        return a.substr(0,a.length()-1);
    }else{
        return a;
    }
}

bool valid(string s){
    if(s.empty())return false;
    if(s[0]=='-')return false;
    if(s=="a"||s=="an"||s=="and"||s=="the")return false;
    for(int i=0;i<s.length();i++){
        if(!((s[i]<='z'&&s[i]>='a')||(s[i]<='Z'&&s[i]>='A')||(s[i]=='-'))){
            return false;
        }
    }
    return true;
}

void read(){
    int cnt=0;
    fstream fs;
    string bf1;
    fs.open(INFILE,ios::in);
    while(getline(fs,bf1)){
        stringstream ss(bf1);
        cnt++;
        while(ss>>bf1){
            bf1=check(bf1);
            if(valid(bf1)){
                strmap[cnt].push_back(bf1);
            }
        }
    }  
}

void write(){
    fstream fs;
    fs.open(OUTFILE,ios::out | ios::trunc);
    for(auto p:linemap){
        fs<<p.first<<':';
        auto bp=unique(p.second.begin(),p.second.end());
        for(auto i=p.second.begin();i<bp;i++){
            fs<<*i;
            if(i!=(bp-1)){
                fs<<',';
            }
        }
        fs<<'\n';
    }
}

int main() {
    read();
    for(auto p:strmap){
        for(string x:p.second){
            linemap[x].push_back(p.first);
        }
    }
    write();
    return 0;
}