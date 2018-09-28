#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1e6+10;
int rt,n;
char str[maxn];
struct fy
{
	int son[26],fail,sum;
}ac[maxn];
void add(char str[])
{
	int l=strlen(str),root=0;
	for(int i=0;i<l;i++)
	{
		int a=str[i]-'a';
		if(!ac[root].son[a]) ac[root].son[a]=++rt;
		root=ac[root].son[a];
	}
	ac[root].sum++;
}
void make()
{
	queue<int> q;
	for(int i=0;i<26;i++)
	{
		if(ac[0].son[i])
		{
			ac[ac[0].son[i]].fail=0;
			q.push(ac[0].son[i]);
		}
	}
	while(!q.empty())
	{
		int a=q.front();q.pop();
		for(int i=0;i<26;i++)
		{
			if(ac[a].son[i])
			{
				ac[ac[a].son[i]].fail=ac[ac[a].fail].son[i];
				q.push(ac[a].son[i]);
			}
			else ac[a].son[i]=ac[ac[a].fail].son[i];
		}
	}
}
int acm(char str[])
{
	int l=strlen(str);
	int root=0,ans=0;
	for(int i=0;i<l;i++)
	{
		root=ac[root].son[str[i]-'a'];
		for(int j=root;j&&ac[j].sum!=-1;j=ac[j].fail)
		{
			ans+=ac[j].sum;
			ac[j].sum=-1;
		}
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",str);
		add(str);
	}
	ac[0].fail=0;
	make();
	scanf("%s",str);
	printf("%d\n",acm(str));
	return 0;
}
