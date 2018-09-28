#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e4+10,maxm=2e5+10;
int n,m,head[maxn],num=1,ans[maxm];
struct fy
{
	int to,next;
}q[maxm<<1];
int son[maxn],now;
bool use[maxm<<1];
void add(int a,int b)
{
	q[++num]=(fy){b,head[a]};head[a]=num;
	q[++num]=(fy){a,head[b]};head[b]=num;
}
void print(int a)
{
	for(int &i=head[a];i;i=q[i].next)
	if(!use[i])
	{
		use[i]=true;
		use[i^1]=true;
		int b=q[i].to;
		print(b);
	}
	ans[++now]=a;
}
int main()
{
	scanf("%d",&n);
	int a,b;
	while(scanf("%d%d",&a,&b)==2)
	{
		m++;
		add(a,b);
		son[a]++;son[b]++;
	}
	bool ge=false;
	int w;
	for(int i=1;i<=n;i++)
	if(son[i]%2) ge=true;
	if(!ge) 
	{
		print(1);
		if(now==(m+1))
		{
			printf("1\n");
			for(int i=1;i<=now;i++)
			printf("%d ",ans[i]);
		}
		else printf("0\n");
	}
	else printf("0\n");
	return 0;
}
