#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=2010;
queue<int>qq;
int n,head[maxn],num,son[maxn],dis[maxn],ans,fa[maxn];
int xx[maxn<<1],w;
struct fy{int to,d,next;}q[2000001];
void add(int a,int b,int c){q[++num]=(fy){b,c,head[a]};head[a]=num;}
void print(int a)
{
	if(fa[a]) print(fa[a]);
	printf("%d ",a);
}
int main()
{
	int x,y,z;scanf("%d",&n);
	while(scanf("%d%d%d",&x,&y,&z)==3){add(x,y,z);son[y]++;}
	for(int i=1;i<=n;i++)if(!son[i])qq.push(i);
	while(!qq.empty())
	{
		int a=qq.front();qq.pop();
		for(int i=head[a];i;i=q[i].next)
		{
			int b=q[i].to;son[b]--;
			if(!son[b]) qq.push(b);
			if(dis[b]<dis[a]+q[i].d) 
			{
				fa[b]=a;
				dis[b]=dis[a]+q[i].d;
				ans=max(ans,dis[b]);
			}
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	if(dis[i]==ans)
	{
		print(i);
		break;
	}
	return 0;
}
