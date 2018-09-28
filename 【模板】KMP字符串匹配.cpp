#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e6+10;
int n,m,next[maxn];
char str[maxn],stt[maxn];
void makenext()
{
	int j=0;
	for(int i=1;i<m;i++)
	{
		while(j&&stt[j]!=stt[i])
		j=next[j-1];
		if(stt[j]==stt[i]) j++;
		next[i]=j;
	}
}
void kmp()
{
	int j=0;
	makenext();
	for(int i=0;i<n;i++)
	{
		while(j&&stt[j]!=str[i])
		j=next[j-1];
		if(stt[j]==str[i]) j++;
		if(j==m) printf("%d\n",i-j+2);
	}
}
int main()
{
	scanf("%s%s",str,stt);
	n=strlen(str);m=strlen(stt);
	kmp();
	for(int i=0;i<m;i++)
	printf("%d ",next[i]);
	return 0;
}
