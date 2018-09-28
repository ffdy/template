#include<cstdio>
#include<algorithm>
#define la (a<<1)
#define ra (a<<1|1)
#define ll long long
using namespace std;
const int maxn=1e5+5;
int n,m;
struct fy{int l,r;ll d,lazy;}q[maxn<<2];
void build(int a,int b,int c)
{
	q[a].l=b;q[a].r=c;
	if(b==c)
	{
		scanf("%d",&q[a].d);
		return;
	}
	int mid=(b+c)>>1;
	build(la,b,mid);
	build(ra,mid+1,c);
	q[a].d=q[la].d+q[ra].d;
}
void down(int a)
{
	if(q[a].lazy)
	{
		q[la].lazy+=q[a].lazy;
		q[ra].lazy+=q[a].lazy;
		q[la].d+=(q[la].r-q[la].l+1)*q[a].lazy;
		q[ra].d+=(q[ra].r-q[ra].l+1)*q[a].lazy;
		q[a].lazy=0;
	}
}
void add(int a,int ql,int qr,ll v)
{
	if(ql<=q[a].l&&q[a].r<=qr)
	{
		q[a].lazy+=v;
		q[a].d+=(q[a].r-q[a].l+1)*v;
	}
	else 
	{
		down(a);
		if(ql<=q[la].r) add(la,ql,qr,v);
		if(q[ra].l<=qr) add(ra,ql,qr,v);
		q[a].d=q[la].d+q[ra].d;
	}
}
ll sum(int a,int ql,int qr)
{
	if(ql<=q[a].l&&q[a].r<=qr) return q[a].d;
	down(a);ll he=0;
	if(ql<=q[la].r) he+=sum(la,ql,qr);
	if(q[ra].l<=qr) he+=sum(ra,ql,qr);
	return he;
}
int main()
{
	scanf("%d%d",&n,&m);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int fl,x,y;ll z;
		scanf("%d",&fl);
		if(fl==1) 
		{
			scanf("%d%d%lld",&x,&y,&z);
			add(1,x,y,z);
		}
		else
		{
			scanf("%d%d",&x,&y);
			printf("%lld\n",sum(1,x,y));
		}
	}
	return 0;
}
