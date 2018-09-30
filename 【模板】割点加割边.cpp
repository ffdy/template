#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=2e4+10,maxm=1e5+10;
int n,m,head[maxn],num,root,cnt;
int dfn[maxn],low[maxn],input;
bool euse[maxn];
struct fy{int to,next;}q[maxm<<1];
struct ffy
{
	int x,y;
	bool operator<(const ffy&a)const{return x==a.x ? y<a.y:x<a.x;};
}cut[maxm<<1];
void add(int a,int b){q[++num]=(fy){b,head[a]};head[a]=num;}
void tar(int a,int fa)
{
	dfn[a]=low[a]=++input;int ee=0;
	for(int i=head[a];i;i=q[i].next)
	{
		int b=q[i].to;
		if(!dfn[b])
		{
			tar(b,a);++ee;low[a]=min(low[a],low[b]);
			if((a==root&&ee>1)||(a!=root&&dfn[a]<=low[b]))
			euse[a]=true;
			if(dfn[a]<low[b])cut[++cnt]=(ffy){min(a,b),max(a,b)};
		}
		else if(b!=fa)low[a]=min(low[a],dfn[b]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);int a,b;
	for(int i=1;i<=m;i++){scanf("%d%d",&a,&b);add(a,b);add(b,a);}
	for(int i=1;i<=n;i++)if(!dfn[i]){root=i;tar(i,0);}
	int ans=0;
	for(int i=1;i<=n;i++)if(euse[i])ans++;
	if(!ans)printf("Null");
	else 
	for(int i=1;i<=n;i++)if(euse[i])printf("%d ",i);
	printf("\n");
	sort(cut+1,cut+1+cnt);
	for(int i=1;i<=cnt;i++)printf("%d %d\n",cut[i].x,cut[i].y);
	return 0;
}
