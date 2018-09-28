#include<queue>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxm=1e5+10,maxn=5e3+10;
int n,m,ans,head[maxn],num,dis[maxn],dis1[maxn];
bool use[maxn];
struct fy{int to,d,next;}q[maxm<<1];
void add(int a,int b,int c){q[++num]=(fy){b,c,head[a]};head[a]=num;}
void sp()
{
	queue<int>qq;qq.push(1);use[1]=true;
	memset(dis,0x3f,sizeof dis);dis[1]=0;
	while(!qq.empty())
	{
		int a=qq.front();qq.pop();use[a]=false;
		for(int i=head[a];i;i=q[i].next)
		{
			int b=q[i].to;
			if(dis[b]>dis[a]+q[i].d)
			{
				dis[b]=dis[a]+q[i].d;
				if(!use[b]){use[b]=true;qq.push(b);}
			}
		}
	}
	qq.push(n);use[n]=true;
	memset(dis1,0x3f,sizeof dis1);dis1[n]=0;
	while(!qq.empty())
	{
		int a=qq.front();qq.pop();use[a]=true;
		for(int i=head[a];i;i=q[i].next)
		{
			int b=q[i].to;
			if(dis1[b]>dis1[a]+q[i].d)
			{
				dis1[b]=dis1[a]+q[i].d;
				if(!use[b]){use[b]=true;qq.push(b);}
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);int a,b,c;
	for(int i=1;i<=m;i++){scanf("%d%d%d",&a,&b,&c);add(a,b,c);add(b,a,c);}
	sp();ans=1e9+7;
	for(int i=1;i<=n;i++)for(int j=head[i];j;j=q[j].next)
	{
		a=q[j].to;b=dis[i]+dis1[a]+q[j].d;
		if(b!=dis[n]&&b<ans)ans=b;
	}
	printf("%d\n",ans);
	return 0;
}
