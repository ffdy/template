#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e3+10;
int n,m,mp[maxn][maxn],l[maxn][maxn],r[maxn][maxn];
int up[maxn][maxn],ans,bns;
int main(){
//	freopen("1.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&mp[i][j]);
			l[i][j]=r[i][j]=j;
			up[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			if(mp[i][j]!=mp[i][j-1])
			l[i][j]=l[i][j-1];
		}
		for(int j=m-1;j;j--){
			if(mp[i][j]=mp[i][j+1])
			r[i][j]=r[i][j+1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i-1&&mp[i][j]!=mp[i-1][j]){
				l[i][j]=max(l[i][j],l[i-1][j]);
				r[i][j]=min(r[i][j],r[i-1][j]);
				up[i][j]+=up[i-1][j];
			}
			int a=r[i][j]+1-l[i][j];
			ans=max(ans,min(a,up[i][j])*min(a,up[i][j]));
			bns=max(bns,a*up[i][j]);
		}
	}
	printf("%d\n%d\n",ans,bns);
	return 0;
}
