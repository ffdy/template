#include<cstdio>
#include<algorithm>
#include<cstring>
#define la (a<<1)
#define ra (a<<1|1)
using namespace std;
const int maxn=1e5+10;
int n,m,head[maxn],num,cnt,R,mod;
int fa[maxn],son[maxn],size[maxn],dep[maxn];
int top[maxn],id[maxn],rk[maxn],v[maxn];
struct fy{int to,next;}q[maxn<<1];
struct ffy{int l,r,d,lazy;}qq[maxn<<2];
void add(int a,int b){q[++num]=(fy){b,head[a]};head[a]=num;}
void dfs(int a,int fat,int de)
{
	fa[a]=fat;dep[a]=de;size[a]=1;
	for(int i=head[a];i;i=q[i].next)
	{
		int b=q[i].to;
		if(b==fat)continue;
		dfs(b,a,de+1);
		size[a]+=size[b];
		if(!son[a]||size[son[a]]<size[b]) son[a]=b;
	}
}
void dfs1(int a,int t)
{
	top[a]=t;id[a]=++cnt;
	rk[cnt]=v[a];
	if(!son[a]) return;
	dfs1(son[a],t);
	for(int i=head[a];i;i=q[i].next)
	{
		int b=q[i].to;
		if(b!=son[a]&&b!=fa[a])dfs1(b,b);
	}
}
void build(int a,int b,int c)
{
	qq[a].l=b;qq[a].r=c;
	if(b==c){qq[a].d=rk[b];return;}
	int mid=b+c>>1;
	build(la,b,mid);build(ra,mid+1,c);
	qq[a].d=(qq[la].d+qq[ra].d)%mod;
}
void down(int a)
{
	int vv=qq[a].lazy;
	if(vv)
	{
		qq[la].lazy=(qq[la].lazy+vv)%mod;
		qq[ra].lazy=(qq[ra].lazy+vv)%mod;
		qq[la].d=(qq[la].d+(qq[la].r+1-qq[la].l)*vv%mod)%mod;
		qq[ra].d=(qq[ra].d+(qq[ra].r+1-qq[ra].l)*vv%mod)%mod;
		qq[a].lazy=0;
	}
}
void qad(int a,int ql,int qr,int vv)
{
	if(ql<=qq[a].l&&qq[a].r<=qr)
	{
		qq[a].lazy=(qq[a].lazy+vv)%mod;
		qq[a].d=(qq[a].d+(qq[a].r+1-qq[a].l)*vv%mod)%mod;
		return ;
	}
	down(a);
	if(ql<=qq[la].r) qad(la,ql,qr,vv);
	if(qq[ra].l<=qr) qad(ra,ql,qr,vv);
	qq[a].d=(qq[la].d+qq[ra].d)%mod;
}
void ad(int a,int b,int vv)
{
	while(top[a]!=top[b])
	{
		if(dep[top[a]]<dep[top[b]]) swap(a,b);
		qad(1,id[top[a]],id[a],vv);
		a=fa[top[a]];
	}
	if(dep[a]>dep[b]) swap(a,b);
	qad(1,id[a],id[b],vv);
}
int qsum(int a,int ql,int qr)
{
	if(ql<=qq[a].l&&qq[a].r<=qr) return qq[a].d%mod;
	down(a);int ans=0;
	if(ql<=qq[la].r) ans=(ans+qsum(la,ql,qr))%mod;
	if(qq[ra].l<=qr) ans=(ans+qsum(ra,ql,qr))%mod;
	return ans;
}
int sum(int a,int b)
{
	int ans=0;
	while(top[a]!=top[b])
	{
		if(dep[top[a]]<dep[top[b]]) swap(a,b);
		ans=(ans+qsum(1,id[top[a]],id[a]))%mod;
		a=fa[top[a]];
	}
	if(dep[a]>dep[b])swap(a,b);
	ans=(ans+qsum(1,id[a],id[b]))%mod;
	return ans;
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&R,&mod);int a,b;
	for(int i=1;i<=n;i++)scanf("%d",&v[i]);
	for(int i=1;i<n;i++){scanf("%d%d",&a,&b);add(a,b);add(b,a);}
	dfs(R,0,1);dfs1(R,R);build(1,1,n);int fl,c;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&fl);
		if(fl==1){scanf("%d%d%d",&a,&b,&c);ad(a,b,c);}
		if(fl==2){scanf("%d%d",&a,&b);printf("%d\n",sum(a,b));}
		if(fl==3){scanf("%d%d",&a,&b);qad(1,id[a],id[a]+size[a]-1,b);}
		if(fl==4){scanf("%d",&a);printf("%d\n",qsum(1,id[a],id[a]+size[a]-1));}
	}
	return 0;
}
