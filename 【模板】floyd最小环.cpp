#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=210,inf=0x3f3f3f3f;
int n,m,xx[maxn],w,fa[maxn][maxn];
ll map[maxn][maxn],dis[maxn][maxn],ans=inf;
void floyd()
{
	ll he;
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<k;i++)for(int j=i+1;j<k;j++)
		{
			he=dis[i][j]+map[j][k]+map[k][i];
			if(he<ans)
			{
				ans=he;w=0;int a=j;
				while(a!=i){xx[++w]=a;a=fa[i][a];}
				xx[++w]=i;xx[++w]=k;
			}
		}
		for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
		{
			he=dis[i][k]+dis[k][j];
			if(he<dis[i][j])
			{
				dis[i][j]=he;
				fa[i][j]=fa[k][j];
			}
		}
	}
}
int main()
{
//	freopen("trip7.in","r",stdin);
	scanf("%d%d",&n,&m);int a,b;ll c;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
	{
		map[i][j]=dis[i][j]=inf;
		fa[i][j]=i;
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lld",&a,&b,&c);c=min(c,dis[a][b]);
		dis[a][b]=dis[b][a]=c;
		map[a][b]=map[b][a]=dis[a][b];
	}
	floyd();
	if(ans==inf)
	{
		printf("No solution.\n");
		return 0;
	}
	for(int i=1;i<=w;i++)printf("%d ",xx[i]);
	return 0;
}
