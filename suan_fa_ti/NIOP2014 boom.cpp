#include <iostream>
#include <vector>
using namespace std;
int main(){
    //answer matrix
    int m[5][5]={{0,-1,1,1,-1},
                {1,0,-1,1,-1},
                {-1,1,0,-1,1},
                {-1,-1,1,0,1},
                {1,1,-1,-1,0}
};
//cout<<m[5][5]<<endl;

   //读数据
    int a,b,c;
    cin>>a>>b>>c;
    vector<int> v1(b);
    for(int i=0;i<b;i++){
        cin>>v1[i];
    }
    vector<int> v2(c);
     for(int i=0;i<c;i++){
        cin>>v2[i];
    }
    //计分
    int cnt1=0,cnt2=0;
    int p,n;
    //模拟
    for(int i=0;i<a;i++){
        int x=i%b;
        int y=i%c;
    //考虑好i从几开始！！！
        p=v1[x];
        n=v2[y];
        if(m[p][n]==1) cnt1++;
        else if(m[p][n]==-1) cnt2++;
        }
    cout<<cnt1<<" "<<cnt2<<endl;
    //system("pause");
    return 0;
    }

