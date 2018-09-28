#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int w[maxn],p[maxn],f[maxn];
int n,m,num;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		for(int j=1;j<=c;j<<=1)
		{
			p[++num]=j*a;w[num]=j*b;
			c-=j;
		}
		if(c){p[++num]=c*a;w[num]=c*b;}
	}
	for(int i=1;i<=num;i++)
	for(int j=m;j>=w[i];j--)
	f[j]=max(f[j],f[j-w[i]]+p[i]);
	printf("%d\n",f[m]);
	return 0;
}
