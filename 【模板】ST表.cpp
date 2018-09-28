#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int n,m,ma[maxn][40],log[maxn];
int main()
{
	scanf("%d%d",&n,&m);
	log[0]=-1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&ma[i][0]);
		if((i&(i-1))==0) log[i]=log[i-1]+1;
		else log[i]=log[i-1];
	}
	for(int j=1;j<=log[n];j++)
	for(int i=1;i+(1<<j)-1<=n;i++)
	ma[i][j]=max(ma[i][j-1],ma[i+(1<<(j-1))][j-1]);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		int k=log[y-x+1];
		printf("%d\n",max(ma[x][k],ma[y-(1<<k)+1][k]));
	}
	return 0;
}
