//单点修改 区间查询 
#include<cstdio>
using namespace std;
const int maxn=5e5+5;
int s[maxn],x,y,z;
int n,m;
int lb(int a){return a&-a;}
void add(int a,int b)
{
	while(a<=n)
	{
		s[a]+=b;
		a+=lb(a);
	}
}
int sum(int a)
{
	int ans=0;
	while(a)
	{
		ans+=s[a];
		a-=lb(a);
	}
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		add(i,x);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x==1) add(y,z);
		else printf("%d\n",sum(z)-sum(y-1));
	}
	return 0;
}
