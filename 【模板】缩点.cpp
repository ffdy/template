#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e4+10,maxm=1e5+10;
int n,m,head[maxn],num,maxl;
int dfn[maxn],low[maxn],input;
int xx[maxn],wei,v[maxn];
int fa[maxn];
bool use[maxn];
struct fy{int from,to,next;}q[maxm<<1];
void add(int a,int b){q[++num]=(fy){a,b,head[a]};head[a]=num;}
void tar(int a)
{
	dfn[a]=low[a]=++input;
	use[a]=true;
	xx[++wei]=a;
	for(int i=head[a];i;i=q[i].next)
	{
		int b=q[i].to;
		if(!dfn[b])
		{
			tar(b);
			low[a]=min(low[a],low[b]);
		}
		else if(use[b])
		{
			low[a]=min(low[a],dfn[b]);
		}
	}
	if(low[a]==dfn[a])
	while(xx[wei+1]!=a)
	{
		fa[xx[wei]]=a;
		if(xx[wei]!=a)
		v[a]+=v[xx[wei]];
		use[xx[wei]]=false;
		wei--;
	}
}
int dfs(int a)
{
	int ans=0;
	for(int i=head[a];i;i=q[i].next)
	ans=max(ans,dfs(q[i].to));
	return v[a]+ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=n;i++)
	if(!dfn[i]) tar(i);
	memset(head,0,sizeof(head));
	for(int i=1;i<=m;i++)
	{
		int aa=fa[q[i].from],bb=fa[q[i].to];
		if(aa!=bb)	add(aa,bb);
	}
	for(int i=1;i<=n;i++)
	{   
		int x=fa[i];
		if(!use[x])
		{
			use[x]=true;
			maxl=max(maxl,dfs(x));
		}
	}
	printf("%d\n",maxl);
	return 0;
}
