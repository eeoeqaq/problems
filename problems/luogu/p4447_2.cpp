#include<cstdio>
#include<map>
std::map<int,int>m;
typedef std::map<int,int>::iterator it;
int main(){
	int n,ans=0x3f3f3f3f;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		int t;
		scanf("%d",&t);
		++m[t];
		//记录图像。
	}
	while(!m.empty()){
		it i=m.begin(),j=m.begin();
		--(*i).second;
		int t=1;
		for(++j;j!=m.end()&&(*j).first==(*i).first+1&&(*j).second>(*i).second;++i,++j){
   			++t;
			--(*j).second;
		}
		//若 i,j 所对应的能力值是连续的，且 i 对应的那一列高度不高于 j，则继续画线。
		i=m.begin();
		while(i!=m.end()&&(*i).second==0){
			m.erase((*i++).first);
		}
		//高度降为 0 后直接删除，便于计算。
		if(t<ans){
			ans=t;
		}
		//记录答案。
	}
	printf("%d",ans);
	return 0;
}
