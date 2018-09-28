#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n,l,w,t=1;
int s[maxn],q[maxn],p[maxn];
int main()
{
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++) scanf("%d",&s[i]);
	for(int i=1;i<=n;i++)
	{
		while(t<=w&&q[w]>s[i]) w--;
		q[++w]=s[i];p[w]=i;
		while(i-p[t]+1>l) t++;
		if(i>=l) printf("%d ",q[t]);
	}
	printf("\n");w=0;t=1;
	for(int i=1;i<=n;i++)
	{
		while(t<=w&&q[w]<s[i]) w--;
		q[++w]=s[i];p[w]=i;
		while(i-p[t]+1>l) t++;
		if(i>=l) printf("%d ",q[t]);
	}
	return 0;
}
