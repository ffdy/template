#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=30;
int s[maxn];
ll f[maxn][maxn][3][3];
ll dp(int w,int n,bool up,bool o)
{
	if(w==1) return 1;
	if(~f[w][n][up][o]) return f[w][n][up][o];
	f[w][n][up][o]=0;
	int upp=up ? s[w-1] : 9;
	for(int i=0;i<=upp;i++)
	if( abs(i-n)>=2 || o ) //特殊自判 
	f[w][n][up][o]+=dp(w-1,i,up&(i==upp),o&(!i));
	return f[w][n][up][o];
}
ll solve(ll a)
{
	if(!a) return 1;//(x-1)可能为0; 
	int b=0;
	while(a)
	{
		s[++b]=a%10;
		a/=10;
	}
	memset(f,-1,sizeof(f));
	ll he=0;
	for(int i=0;i<=s[b];i++)
	he+=dp(b,i,i==s[b],!i);
	return he;
}
int main()
{
	ll x,y;
	scanf("%lld%lld",&x,&y);
	printf("%lld\n",solve(y)-solve(x-1) );
	return 0;
}
