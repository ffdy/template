#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5010,inf=1e9+7;
int n,m,dis[maxn];
bool use[maxn];
int ans,map[maxn][maxn];
int prim()
{
	int a=1,time=0;ans=0;
	memset(dis,0x3f,sizeof dis);
	while(++time<n)
	{
		use[a]=true;
		for(int i=1;i<=n;i++)
		if(!use[i]&&map[a][i]<dis[i])dis[i]=map[a][i];
		double mm=map[0][0];
		for(int i=1;i<=n;i++)if(!use[i]&&mm>dis[i])
		{a=i;mm=dis[i];}
		if(mm==map[0][0])return -1;
		ans+=mm;
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);memset(map,0x3f,sizeof map);
	int a,b,c;for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		map[a][b]=min(map[a][b],c);
		map[b][a]=map[a][b];
	}
	a=prim();
	if(a==-1)printf("orz\n");
	else printf("%d\n",ans);
	return 0;
}
