#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=1e7+5;
int n,m;
int x;
int use[maxn];
bool can(int a)
{
	if(a==1) return false;
	if(a==2||a==3) return true;
	if(a%6!=1&&a%6!=5) return false;
	int b=sqrt(a);
	for(int i=5;i<=b;i+=6)
	if(a%i==0||a%(i+2)==0)
	return false;
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		if(use[x]==1) printf("No\n");
		else if(use[x]==2) printf("Yes\n");
		else if(can(x)) 
		{
			use[x]=2;
			printf("Yes\n");
		}
		else 
		{
			use[x]=1;
			printf("No\n");
		}
	}
	return 0;
}
