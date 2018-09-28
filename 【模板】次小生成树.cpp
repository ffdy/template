#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e4+10,maxm=1e5+10;
int n,m,x,y,z,ans,dep[maxn];
bool usee[maxm];
int fa[maxn],pa[maxn][30],maxx[maxn][30];
struct fy{int from,to,d,next;}q[maxm];
fy e[maxn<<1]; 
bool cmp(fy a,fy b){return a.d<b.d;}
int head[maxn],num;
void add(int a,int b,int c)
{
	e[++num]=(fy){a,b,c,head[a]};head[a]=num;
	e[++num]=(fy){b,a,c,head[b]};head[b]=num;
}
int f(int a){while(fa[a]!=a) a=fa[a]=fa[fa[a]];return a;}
void dfs(int a,int p)
{
	dep[a]=dep[p]+1;pa[a][0]=p;
	for(int i=1;(1<<i)<=dep[a];i++)
	{
		pa[a][i]=pa[pa[a][i-1]][i-1];
		maxx[a][i]=max(maxx[a][i-1],maxx[pa[a][i-1]][i-1]);
	}
	for(int i=head[a];i;i=e[i].next)
	{
		int b=e[i].to;
		if(b!=p)
		{
			maxx[b][0]=e[i].d;
			dfs(b,a);
		}
	}
}
int lca(int a,int b)
{
	int re=0;
	if(dep[a]>dep[b])
	{
		int cc=a;
		a=b;
		b=cc;
	}
	for(int i=25;i>=0;i--)
	if(dep[pa[b][i]]>=dep[a])
	{
		re=max(re,maxx[b][i]);
		b=pa[b][i];
	}
	if(a==b) return re;
	for(int i=25;i>=0;i--)
	if(pa[a][i]!=pa[b][i])
	{
		re=max(re,max(maxx[a][i],maxx[b][i]));
		a=pa[a][i];b=pa[b][i];
	}
	return re=max(re,max(maxx[a][0],maxx[b][0]));
}
bool kls()
{
	int g=0,x,y;bool can=false;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		x=f(q[i].from),y=f(q[i].to);
		if(x!=y) 
		{
			fa[x]=y;ans+=q[i].d;
			g++;usee[i]=true;
			add(q[i].from,q[i].to,q[i].d);
			if(g==n-1){can=true;break;} 
		}
	}
	if(can) return true;
	return false;
}
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		memset(head,0,sizeof head);num=0;
		memset(maxx,0,sizeof maxx);ans=0;
		memset(pa,0,sizeof pa);memset(dep,0,sizeof dep);
		memset(usee,false,sizeof usee);
		scanf("%d%d",&n,&m);int ad=0x7fffffff;
		for(int i=1;i<=m;i++) scanf("%d%d%d",&q[i].from,&q[i].to,&q[i].d);
		sort(q+1,q+1+m,cmp);
		if(!kls()) printf("-1\n");
		else
		{	
			dfs(1,0);
			for(int i=1;i<=m;i++)
			if(!usee[i])ad=min(ad,q[i].d-lca(q[i].from,q[i].to));
			if(ad==0x7fffffff) printf("-1\n");
			else printf("%d\n",ans+ad);
		}
	}
	return 0;
}
