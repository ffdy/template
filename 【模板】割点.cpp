#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int head[maxn],num;
struct fy{int to,next;}q[maxn<<1];
int dfn[maxn],low[maxn],input,fa[maxn],n,m,ans;
bool use[maxn];
void add(int a,int b)
{
	q[++num]=(fy){b,head[a]};head[a]=num;
	q[++num]=(fy){a,head[b]};head[b]=num;
}
void tar(int a,int b)
{
	int ch=0;
	dfn[a]=low[a]=++input;
	for(int i=head[a];i;i=q[i].next)
	{
		int c=q[i].to;
		if(c==b) continue;
		if(!dfn[c])
		{
			fa[c]=a;
			ch++;
			tar(c,a);
			low[a]=min(low[a],low[c]);
			if(!fa[a]&&ch>=2&&!use[a])
			{
				ans++;
				use[a]=true;
			}
			else if(fa[a]&&low[c]>dfn[a]&&!use[a])
			{
				ans++;
				use[a]=true;
			}
		}
		else low[a]=min(low[a],low[c]);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	for(int i=1;i<=n;i++)
	if(!dfn[i]) tar(i,i);
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	if(use[i]) printf("%d ",i);
	return 0;
}
