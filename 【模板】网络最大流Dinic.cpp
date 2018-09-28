#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1e4+5,maxm=1e5+5,inf=0x7ffffff;
int n,m,s,t,ans;
int head[maxn],num=1/*!!!!*/,cur[maxn],dep[maxn];
struct fy{int to,next,c;}q[maxm<<1];
void add(int a,int b,int c){
	q[++num]=(fy){b,head[a],c};head[a]=num;
	q[++num]=(fy){a,head[b],0};head[b]=num;
} 
bool bfs()
{
	memset(dep,0,sizeof dep);
	queue<int>qq;
	qq.push(s);
	dep[s]=1;
	while(!qq.empty())
	{
		int a=qq.front();qq.pop();
		for(int i=head[a];i;i=q[i].next)
		{
			int b=q[i].to;
			if(!dep[b]&&q[i].c)
			{
				dep[b]=dep[a]+1;
				qq.push(b);
			}
		}
	}
	return dep[t];
}
int dfs(int a,int flow)
{
	if(a==t||!flow) return flow;
	int fl=0,f;
	for(int &i=cur[a];i;i=q[i].next)
	{
		int b=q[i].to;
		if(q[i].c&&dep[b]==dep[a]+1&&(f=dfs(b,min(flow,q[i].c))))
		{
			fl+=f;flow-=f;
			q[i].c-=f;q[i^1].c+=f;
			if(!flow) break;
		}
	}
	return fl;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
	}
	while(bfs())
	{
		for(int i=1;i<=n;i++) cur[i]=head[i];
		ans+=dfs(s,inf);
	}
	printf("%d\n",ans);
	return 0;
}
