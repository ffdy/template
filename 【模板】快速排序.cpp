#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e5+5;
int n;
int aa[maxn];
int bb[maxn];
void s(int a,int b)
{
	int mid=(a+b)/2;
	if(a!=b)
	{
		s(a,mid);
		s(mid+1,b);
	}
	memset(bb,0,sizeof(b));
	int x=a-1,y=mid+1,z=a;
	while(a<=mid&&y<=b)
	{
		if(aa[a]>aa[y]) 
		{
			bb[++x]=aa[y];
			y++;
		}
		else
		{
			bb[++x]=aa[a];
			a++;
		}
	}
	for(int i=a;i<=mid;i++)
	bb[++x]=aa[i];
	for(int i=y;i<=b;i++)
	bb[++x]=aa[i];
	for(int i=z;i<=b;i++)
	aa[i]=bb[i];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&aa[i]);
	s(1,n);
	for(int i=1;i<=n;i++)
	printf("%d ",aa[i]);
	return 0;
}
