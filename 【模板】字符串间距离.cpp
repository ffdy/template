#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1010;
int f[maxn][maxn],n;
char str1[maxn],str2[maxn];
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s%s",str1,str2);
		int l1=strlen(str1),l2=strlen(str2);
		for(int i=1;i<=l1;i++)
		f[i][0]=i;
		for(int i=1;i<=l2;i++)
		f[0][i]=i;
		for(int i=0;i<l1;i++)
		for(int j=0;j<l2;j++)
		if(str1[i]==str2[j]) f[i+1][j+1]=f[i][j];
		else f[i+1][j+1]=min(f[i][j]+1,min(f[i+1][j]+1,f[i][j+1]+1));
		printf("%d\n",f[l1][l2]);
	}
	return 0;
}
