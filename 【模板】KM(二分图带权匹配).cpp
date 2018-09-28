#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=30,inf=0x7fffffff;
int n,v[maxn][maxn],v1[maxn][maxn],lx[maxn],ly[maxn],p[maxn],ans,minx;
bool usex[maxn],usey[maxn];
bool dfs(int a)
{
	usex[a]=true;
	for(int i=1;i<=n;i++)if(!usey[i])
	{
		int t=lx[a]+ly[i]-v[a][i];
		if(t==0)
		{
			usey[i]=true;
			if(!p[i]||dfs(p[i]))
			{p[i]=a;return true;}
		}
		else if(t)minx=min(minx,t);
	}
	return false;
}
void km()
{
	for(int i=1;i<=n;i++)while(1)
	{
		minx=inf;memset(usex,false,sizeof usex);memset(usey,false,sizeof usey);
		if(dfs(i)) break;
		for(int j=1;j<=n;j++)if(usex[j])lx[j]-=minx;
		for(int j=1;j<=n;j++)if(usey[j])ly[j]+=minx;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&v[i][j]);
	// 最小匹配初值反转为负 
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)lx[i]=max(lx[i],v[i][j]);
	km();
	for(int i=1;i<=n;i++)ans+=v[p[i]][i];printf("%d\n",ans);
	return 0;
}
