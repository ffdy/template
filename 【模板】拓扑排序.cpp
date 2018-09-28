#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=2010;
int n,head[maxn],num,son[maxn];
queue<int>qq;bool use[maxn];
int xx[maxn<<1],w;
struct fy{int to,next;}q[maxn*maxn];
void add(int a,int b){q[++num]=(fy){b,head[a]};head[a]=num;}
int main()
{
	scanf("%d",&n);
	int x,y;
	for(int i=1;i<=n;i++)while(scanf("%d",&x)==1&&x!=0) add(i,x),son[x]++;
	for(int i=1;i<=n;i++)if(!son[i]){qq.push(i);}
	while(!qq.empty())
	{
		int a=qq.front();qq.pop();xx[++w]=a;
		for(int i=head[a];i;i=q[i].next)
		{
			int b=q[i].to;son[b]--;
			if(!son[b])qq.push(b);
		}
	}
	if(w!=n) printf("NO\n");
	else 
	{
		for(int i=1;i<=w;i++) printf("%d ",xx[i]);
	}
	return 0;
}
