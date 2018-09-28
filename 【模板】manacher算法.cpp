#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=11e6+10;
char str[maxn],strr[maxn<<1];
int n;
int len[maxn<<1];
int main()
{
	scanf("%s",str);
	n=strlen(str);
	strr[0]='@';
	for(int i=0;i<=n;i++)
	{
		strr[(i<<1)+2]=str[i];
		strr[(i<<1)+1]='#';
	}
	int mx=0,ans=0,mid=0;
	for(int i=1;i<=(n<<1)+2;i++)
	{
		len[i]=(mx>i ? min(mx-i,len[mid*2-i]):1);
		while(strr[i-len[i]]==strr[i+len[i]]) len[i]++;
		if(i+len[i]>mx)
		{
			mx=len[i]+i;
			mid=i;
		} 
		ans=max(ans,len[i]);
	}
	printf("%d",ans-1);
	return 0;
}
