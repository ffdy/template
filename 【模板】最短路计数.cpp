#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=2e3+10;
int n,m,head[maxn],num,dis[maxn],s[maxn];
int ed[maxn][maxn];
struct fy{int to,d,next;}q[maxn*maxn];
struct ffy{int u,d;bool operator<(const ffy a)const{return d>a.d;};};
priority_queue<ffy>qq;
void add(int a,int b,int c){q[++num]=(fy){b,c,head[a]};head[a]=num;}
void dj()
{
	memset(dis,0x3f,sizeof dis);dis[1]=0;s[1]=1;
	qq.push((ffy){1,0});
	while(!qq.empty())
	{
		ffy a=qq.top();qq.pop();
		if(a.d!=dis[a.u]) continue;
		for(int i=head[a.u];i;i=q[i].next)
		{
			int b=q[i].to;
			if(dis[b]>dis[a.u]+q[i].d){dis[b]=dis[a.u]+q[i].d;s[b]=s[a.u];qq.push((ffy){b,dis[b]});}
			else if(dis[b]==dis[a.u]+q[i].d)s[b]=(s[b]+s[a.u]);
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);int x,y,z;memset(ed,0x3f,sizeof ed);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(ed[x][y]>z)
		{
			ed[x][y]=z;
			add(x,y,z);
		}
	}
	dj();
	if(dis[n]!=dis[0]) printf("%d %d\n",dis[n],s[n]);
	else printf("No answer\n");
	return 0;
}
