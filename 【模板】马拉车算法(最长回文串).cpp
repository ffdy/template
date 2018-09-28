#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=2e6+20;
int n;
char str[maxn],strr[maxn<<1];
int l[maxn<<1];
int main()
{
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	scanf("%d%s",&n,str);
	strr[0]='@';
	for(int i=0;i<=n;i++)
	{
		strr[(i<<1)+2]=str[i];
		strr[(i<<1)+1]='#';
	}
	int mid=0,mx=0,ans=0;
	for(int i=1;i<=(n<<1);i++)
	{
		l[i]=mx>i ? min(mx-i,l[mid*2-i]):1;
		while(strr[i-l[i]]==strr[i+l[i]]) l[i]++;
		if(mx<l[i]+i)
		{
			mx=l[i]+i;
			mid=i;
		} 
		ans=max(ans,l[i]);
	}
	printf("%d",ans-1);
	return 0;
}
