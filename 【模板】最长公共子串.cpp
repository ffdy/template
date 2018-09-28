#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=3110;
int l1,l2;
char str1[maxn],str2[maxn];
int f[maxn][maxn];
int main()
{
	scanf("%s%s",str1,str2);
	l1=strlen(str1);l2=strlen(str2);
	for(int i=1;i<=l1;i++)
	for(int j=1;j<=l2;j++)
	if(str1[i-1]==str2[j-1]) f[i][j]=f[i-1][j-1]+1;
	else f[i][j]=max(f[i-1][j],f[i][j-1]);
	printf("%d\n",f[l1][l2]);
	return 0;
}
