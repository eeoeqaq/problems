//思路是对的，但是超时了。题解里有和我思路一样的却没超时。哭了。
#include<algorithm>
#include <iostream>
#include<vector>
using namespace std;vector<int>cnt1;
int n;vector<int>num1;
int main() {
    cin>>n;
    num1.resize(n);
    for(int &x:num1){
        cin>>x;
    }
    sort(num1.begin(),num1.end());
    
    for(int i=0;i<n;i++){
        if(i==0){
            cnt1.push_back(1);   
        }else{
            if(num1[i]==num1[i-1]){
                cnt1.back()++;
            }else if((num1[i]-num1[i-1])==1){
                cnt1.push_back(1);  
            }else{
                cnt1.push_back(0); 
                cnt1.push_back(1); 
            }
        }
    }
    int ans=100000;int bfans=0;bool flag=true,flag1=false;
    while(flag){
        flag=false;
        for(int i=0;i<cnt1.size();i++){
            if(i==cnt1.size()-1||cnt1[i]>cnt1[i+1]){
                flag1=true;
            }
            if(cnt1[i]>0){
                bfans++;
                cnt1[i]--;
            }
            if(flag1){
                flag1=false;
                break;
            }
        }
        //cout<<bfans<<endl;
        if(bfans){
            flag=true;
            if(bfans<ans)ans=bfans;
        }
        bfans=0;
    }
    cout<<ans<<endl;
    return 0;
}