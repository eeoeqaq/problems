#include <iostream>
#include<string>
#include <cstdio> 
using namespace std;
int n;
int num[100];
char ans[5][400];
string c0="XXXX.XX.XX.XXXX";
string c1="..X..X..X..X..X";
string c2="XXX..XXXXX..XXX";
string c3="XXX..XXXX..XXXX";
string c4="X.XX.XXXX..X..X";
string c5="XXXX..XXX..XXXX";
string c6="XXXX..XXXX.XXXX";
string c7="XXX..X..X..X..X";
string c8="XXXX.XXXXX.XXXX";
string c9="XXXX.XXXX..XXXX";
void write(int k,int st){
    switch(k){
        case 0:
       
        for(int i=0;i<5;i++){
            for(int j=st;j<st+3;j++){
                ans[i][j]=c0[i*3+j-st];
            }
        }
        break;
        case 1:
        
        for(int i=0;i<5;i++){
            for(int j=st;j<st+3;j++){
                ans[i][j]=c1[i*3+j-st];
            }
        }
        break;
        case 2:
       
        for(int i=0;i<5;i++){
            for(int j=st;j<st+3;j++){
                ans[i][j]=c2[i*3+j-st];
            }
        }
        break;
        case 3:
        
        for(int i=0;i<5;i++){
            for(int j=st;j<st+3;j++){
                ans[i][j]=c3[i*3+j-st];
            }
        }
        break;
        case 4:
        
        for(int i=0;i<5;i++){
            for(int j=st;j<st+3;j++){
                ans[i][j]=c4[i*3+j-st];
            }
        }
        break;
        case 5:
      
        for(int i=0;i<5;i++){
            for(int j=st;j<st+3;j++){
                ans[i][j]=c5[i*3+j-st];
            }
        }
        break;
        case 6:
       
        for(int i=0;i<5;i++){
            for(int j=st;j<st+3;j++){
                ans[i][j]=c6[i*3+j-st];
            }
        }
        break;
        case 7:
       
        for(int i=0;i<5;i++){
            for(int j=st;j<st+3;j++){
                ans[i][j]=c7[i*3+j-st];
            }
        }
        break;
        case 8:
        
        for(int i=0;i<5;i++){
            for(int j=st;j<st+3;j++){
                ans[i][j]=c8[i*3+j-st];
            }
        }
        break;
        case 9:
        
        for(int i=0;i<5;i++){
            for(int j=st;j<st+3;j++){
                ans[i][j]=c9[i*3+j-st];
            }
        }
        break;
    }

}

int main(){
/*     string s;
cin >> n >> s;
for (int i = 0; i < n; i++){
    num[i] = s[i] - '0';
    cout<<num[i];
}*/

   cin>>n;
    getchar();
    for(int i=0;i<n;i++){
      num[i]=getchar()-'0';
    cout<<num[i]<<" " ;
    }
  
    for(int i=0;i<n;i++){
        int st=i*4;
        //cout<<num[i]<<st;
        write(num[i],st);
    }
   
    for(int i=0;i<5;i++){
        for(int j=0;j<n*4-1;j++){
            if(ans[i][j]==0){cout<<'.';}
            else{cout<<ans[i][j];}
        }
         cout<<endl;
        }
       cout<<endl;
    }