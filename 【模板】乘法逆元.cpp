#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=3e6+10;
int n;
ll mod,inv[maxn];
int main()
{
	scanf("%d%lld",&n,&mod);
	inv[1]=1;printf("1\n");
	for(int i=2;i<=n;i++)
	{
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		printf("%lld\n",inv[i]);
	}
	return 0;
}
