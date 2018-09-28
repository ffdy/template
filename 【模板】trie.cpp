#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n;
int root=1;
char str[110];
struct fy
{
	int son[26];
	bool use=false;
}trie[maxn];
bool ins(char str[])
{
	int l=strlen(str),rt=1;
	for(int i=0;i<l;i++)
	{
		if(str[i]<'a') str[i]+=32;
		int a=str[i]-'a';
		if(!trie[rt].son[a]) trie[rt].son[a]=++root;
		rt=trie[rt].son[a];
	}
//	for(int i=0;i<l;i++) printf("%c",str[i]);
//	printf("\n");
	if(trie[rt].use) return true;
	trie[rt].use=true;
	return false;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str);
		if(ins(str)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
