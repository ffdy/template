#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=16;
int n,d[maxn][maxn],f[maxn][1<<maxn],ans=1e9+10;
int main()
{
	scanf("%d",&n);
	memset(f,66,sizeof f);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	scanf("%d",&d[i][j]);
	f[1][1]=0;
	for(int s=1;s<(1<<maxn);s++)
	for(int i=1;i<=n;i++)
	if(s&(1<<i-1))
	{
		for(int j=1;j<=n;j++)
		if(!(s&(1<<j-1)))
		f[j][s|(1<<j-1)]=min(f[i][s]+d[i][j],f[j][s|(1<<j-1)]);
	}
	for(int i=2;i<=n;i++)
	ans=min(ans,f[i][(1<<n)-1]+d[i][1]);
	printf("%d\n",ans);
	return 0;
}
