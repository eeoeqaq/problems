#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int n;
struct pers{
    int a,b;
    pers()=default;
    pers(int x ,int y):a(x),b(y){};
};
vector<pers> qn;

bool cm(pers x,pers y){
    return max(y.b,x.a*x.b)<max(x.b,y.a*y.b);
} 

void mul (vector<int>& ans ,int a){
    for(int &x:ans){
        x*=a;
    }
    for(int i=0;i<ans.size()-1;i++){
        if(ans[i]>=10){
            ans[i+1]+=(ans[i]/10);
            ans[i]%=10;
        }
    }
}

bool cmp (vector<int> ans1,vector<int> ans2){
    for(int i=ans1.size()-1;i>=0;i--){
        if(ans1[i]!=ans2[i]){
            return ans1[i]<ans2[i];
        }
    }
    return true;
}

void print(vector<int> ans){
    int i=ans.size()-1;
    for(;i>=0;i--){
        if(ans[i]!=0)break;
        if(i==0)cout<<"0";
    }
    for(;i>=0;i--){
        cout<<ans[i];
    }
    cout<<endl;
}

void wt(vector<int> &ans1,int i){
    int cnt=0;
    while(i){
        ans1[cnt]=i%10;
        cnt++;
        i/=10;
    }
}

void dv(const vector<int>& ans1,int i,vector<int> &bf){
    fill(bf.begin(), bf.end(), 0);
    int k=(int)ans1.size()-1;
    long long num=0;
    for(;k>=0;k--){
        if(ans1[k]!=0)break;
    }
    for(;k>=0;k--){
        num=num*10+ans1[k];
        if(num>=i){
            bf[k]=num/i;
            num%=i;
        }
    }
}

int size1=5000;
vector<int>bfans(size1),bf(size1),max1(size1);

int main() {
    cin>>n;
    qn.resize(n+1);
    for(int i=0;i<=n;i++){
        int bf1,bf2;
        cin>>bf1>>bf2;
        qn[i]=pers(bf1,bf2);
    }
    sort(qn.begin()+1,qn.end(),cm);
    //需要高精度：单因素乘法、除法、比较、输出（复制？）
    wt(bf,qn[0].a);
    for(int i=1;i<=n;i++){
        dv(bf,qn[i].b,bfans);
        if(cmp(max1,bfans)){max1=bfans;}
        mul(bf,qn[i].a);
    }
    print(max1);
    return 0;
}