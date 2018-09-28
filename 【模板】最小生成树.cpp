#include<cstdio>
#include<algorithm>
#define ll long long 
using namespace std;
const int maxn=2e5+10,maxm=5e5+10;
int n,m;
struct fy{int from,to,d;}q[maxm];
int fa[maxn],s;
ll ans;
int f(int a){if(fa[a]!=a) fa[a]=f(fa[a]);return fa[a];}
bool cmp(fy a,fy b){return a.d<b.d;}
int main()
{
//	freopen("mst1.in","r",stdin);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	fa[i]=i; 
	for(int i=1;i<=m;i++)
	scanf("%d%d%d",&q[i].from,&q[i].to,&q[i].d);
	sort(q+1,q+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		int x=f(q[i].from);
		int y=f(q[i].to);
		if(x!=y)
		{
			fa[x]=y;
			s++;
			ans+=q[i].d;
			if(s==n-1) break;
		}
	}
	printf("%d",ans);
	return 0;
}
