#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
const int maxn=4e6+10;
int n,m,ans,op;
int fa[maxn];
int f(int a)
{
	if(fa[a]!=a) fa[a]=f(fa[a]);
	return fa[a];
}
int read()
{
	int x=0;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar());
	for(;isdigit(ch);ch=getchar())
	x=(x<<3)+(x<<1)+ch-48;
	return x;
} 
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)
	fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;op=read();
		x=read();y=read();
		int f1=f(x);
		int f2=f(y);
		if(op==0) fa[f1]=f2;
		if(op==1) 
		{
			if(f1==f2) ans=(ans<<1)+1;
			else ans<<=1;
			ans%=998244353;
		} 
	}
	printf("%d",ans);
	return 0;
}
