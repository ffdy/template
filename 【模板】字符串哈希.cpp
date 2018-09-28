#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll unsigned long long 
using namespace std;
const int maxn=1e4+10;
char str[maxn];
ll ha[maxn],ans;
int n;
int prime=233317; 
ll mod=212370440130137957ll,base=233317;
ll hash(char str[])
{
	int l=strlen(str);
	ll bns=0;
	for(int i=0;i<l;i++) 
	bns=(bns*base+(ll)str[i])%mod+prime;
	return bns;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str);
		ha[i]=hash(str);
	}
	sort(ha+1,ha+1+n);
	for(int i=1;i<=n;i++)
	if(ha[i]!=ha[i+1]) ans++;
	printf("%d\n",ans);
	return 0;
}
