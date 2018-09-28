#include<cstdio>
#include<algorithm>
#define ll long long
#define la (a<<1)
#define ra (a<<1|1)
using namespace std;
const int maxn=1e5+5;
int n,m,x,y;
ll p,z;
struct fy{int l,r;ll d,lx=1,lad;}q[maxn<<2];
void build(int a,int b,int c)
{
	q[a].l=b;q[a].r=c;
	if(b==c)
	{
		scanf("%lld",&q[a].d);
		return ;
	}
	int mid=b+c>>1;
	build(la,b,mid);build(ra,mid+1,c);
	q[a].d=(q[la].d+q[ra].d)%p;
}
void down(int a)
{
	ll v=q[a].lx;
	if(v!=1)
	{
		q[la].lx=q[la].lx*v%p;q[ra].lx=q[ra].lx*v%p;
		q[la].lad=q[la].lad*v%p;q[ra].lad=q[ra].lad*v%p;
		q[la].d=q[la].d*v%p;q[ra].d=q[ra].d*v%p;
		q[a].lx=1;
	}
	v=q[a].lad;
	if(v!=0)
	{
		q[la].lad=(q[la].lad+v)%p;q[ra].lad=(q[ra].lad+v)%p;
		q[la].d=(q[la].d+(q[la].r-q[la].l+1)%p*v)%p;
		q[ra].d=(q[ra].d+(q[ra].r-q[ra].l+1)%p*v)%p;
		q[a].lad=0;
	}
}
void add(int a,int ql,int qr,ll v)
{
	if(ql<=q[a].l&&q[a].r<=qr)
	{
		q[a].lad=(q[a].lad+v)%p;
		q[a].d=(q[a].d+(q[a].r-q[a].l+1)%p*v)%p;
		return ;
	}
	down(a);
	if(ql<=q[la].r) add(la,ql,qr,v);
	if(q[ra].l<=qr) add(ra,ql,qr,v);
	q[a].d=(q[la].d+q[ra].d)%p;
}
void xx(int a,int ql,int qr,ll v)
{
	if(ql<=q[a].l&&q[a].r<=qr) 
	{
		q[a].lad=q[a].lad*v%p;
		q[a].lx=q[a].lx*v%p;
		q[a].d=q[a].d*v%p;
		return;
	}
	down(a);
	if(ql<=q[la].r) xx(la,ql,qr,v);
	if(q[ra].l<=qr) xx(ra,ql,qr,v);
	q[a].d=(q[la].d+q[ra].d)%p;
}
ll sum(int a,int ql,int qr)
{
	if(ql<=q[a].l&&q[a].r<=qr) return q[a].d%p;
	down(a);ll ans=0;
	if(ql<=q[la].r) ans+=sum(la,ql,qr);
	if(q[ra].l<=qr) ans+=sum(ra,ql,qr);
	return ans%p;
}
int main()
{
	scanf("%d%lld",&n,&p);
	build(1,1,n);scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int fl;
		scanf("%d",&fl);
		if(fl!=3)
		{
			scanf("%d%d%lld",&x,&y,&z);
			if(fl==1) xx(1,x,y,z);
			else add(1,x,y,z);
		}
		else 
		{
			scanf("%d%d",&x,&y);
			printf("%lld\n",sum(1,x,y));
		}
	}
	return 0;
}
