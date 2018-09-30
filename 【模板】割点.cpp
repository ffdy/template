#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=5e4+10;
int n,m,head[maxn],num,root;
int dfn[maxn],low[maxn],input;
bool use[maxn];
struct fy{int to,next;}q[maxn<<2];
void add(int a,int b){q[++num]=(fy){b,head[a]};head[a]=num;}
void tar(int a)
{
	dfn[a]=low[a]=++input;
	int cnt=0;
	for(int i=head[a];i;i=q[i].next)
	{
		int b=q[i].to;
		if(!dfn[b])
		{
			cnt++;tar(b);
			low[a]=min(low[a],low[b]);
			if((a==root&&cnt>1)||(a!=root&&dfn[a]<=low[b]))use[a]=true;
		}
		else low[a]=min(low[a],dfn[b]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);int a,b;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);add(a,b);add(b,a);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])
	{root=i;tar(i);}
	int ans=0;
	for(int i=1;i<=n;i++)if(use[i])ans++;
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)if(use[i])printf("%d ",i);
	return 0;
}
