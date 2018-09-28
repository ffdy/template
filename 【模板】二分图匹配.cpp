#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=2e3+5;
int n,m,e;
int head[maxn],num;
struct fy{int from,to,next;}q[maxn*maxn];
bool use[maxn];
int p[maxn],ans;
bool find(int a)
{
	for(int i=head[a];i;i=q[i].next)
	{
		int b=q[i].to;
		if(!use[b])
		{
			use[b]=true;
			if(!p[b]||find(p[b]))
			{
				p[b]=a;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	scanf("%d%d%d",&n,&m,&e);
	for(int i=1;i<=e;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x<=n&&y<=m) 
		q[++num]=(fy){x,y,head[x]},head[x]=num;
	}
	for(int i=1;i<=n;i++)
	{
		memset(use,false,sizeof(use));
		if(find(i)) ans++;
	}
	printf("%d",ans);
	return 0;
}
