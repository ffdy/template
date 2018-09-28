#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
//const int inf=1e9+7;
ll aa,bb,cc;
ll poww(ll a,ll b,ll c)
{
	ll ans=1,ba=a%c;
	while(b)
	{
		if(b&1) ans=ans*ba%c;
		ba=ba*ba%c;
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%lld%lld%lld",&aa,&bb,&cc);
	printf("%lld^%lld mod %lld=%lld\n",aa,bb,cc,poww(aa,bb,cc)%cc);
	return 0;
}
