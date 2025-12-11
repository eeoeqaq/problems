#include<iostream>
using namespace std;

int ca,cb,cc,cd,best,ans;
int a[20],b[20],c[20],d[20];
double half,diff;double mindiff=2000;

void dfs(int *k,int ck,int cnt,int sum){
    if(cnt>=ck){
        diff=abs(half-sum);
        if(diff<mindiff){
            mindiff=diff;
            best=sum;
        }
        return;
    }
    dfs(k,ck,cnt+1,sum+k[cnt]);
    dfs(k,ck,cnt+1,sum);
}

int sourch(int *k,int ck){
    int sum=0;
    for(int i=0;i<ck;i++){
        sum+=k[i];
    }
    half=sum/2.0;
    dfs(k,ck,0,0);
    mindiff=2000;
    if(best>half){
        return best;  
    }else{
        return sum-best;
    }

}



int main(){
    cin>>ca>>cb>>cc>>cd;
    for(int i=0;i<ca;i++){
        cin>>a[i];
    }
    for(int i=0;i<cb;i++){
        cin>>b[i];
    }
    for(int i=0;i<cc;i++){
        cin>>c[i];
    }
    for(int i=0;i<cd;i++){
        cin>>d[i];
    }
    ans=sourch(a,ca)+sourch(b,cb)+sourch(c,cc)+sourch(d,cd);
    cout<<ans;
//<<sourch(a,ca)<<endl<<sourch(b,cb)<<endl<<sourch(c,cc)<<endl<<sourch(d,cd)<<endl
}