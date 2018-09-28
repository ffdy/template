#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=2e5+10,inf=1e9;
int n;
int h[maxn];
int l,r;
ll can(int a)//ÊÓÇé¿ö 
{
	ll ans=0,bns;
	for(int i=1;i<=n;i++)
	{
		bns=h[i]-a-i;
		if(bns<0) bns*=-1;
		ans+=bns;
	}
	return ans;
}
int main()
{
//	freopen("snake.in","r",stdin);
//	freopen("snake.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&h[i]);
	l=-1*inf;r=inf;
	while(l<=r-3)
	{
		
		int mid=l+(r-l)/3,mmid=r-(r-l)/3;
		if(can(mid)>can(mmid)) l=mid;
		else r=mmid;
	}
	printf("%lld\n",min(can(l),min(can(l+1),can(r))));
	return 0;
}
