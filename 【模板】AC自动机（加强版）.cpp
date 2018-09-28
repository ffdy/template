#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=2e4+10,maxl=1e6+10;
int n,rt,bi;
char str[160][80],mu[maxl];
int ans[maxl];
struct fy
{
	int son[26],fail,w;
}ac[maxl];
void add(char str[],int v)
{
	int l=strlen(str),root=0;
	for(int i=0;i<l;i++)
	{
		int a=str[i]-'a';
		if(!ac[root].son[a]) ac[root].son[a]=++rt;
		root=ac[root].son[a];
	}
	ac[root].w=v;
}
void make()
{
	queue<int>q;
	for(int i=0;i<26;i++)
	if(ac[0].son[i]) q.push(ac[0].son[i]);
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
void acm(char str[])
{
	int l=strlen(str),root=0;
	for(int i=0;i<l;i++)
	{
		root=ac[root].son[str[i]-'a'];
		for(int j=root;j;j=ac[j].fail)
		if(ac[j].w)
		{
			ans[ac[j].w]++;
			bi=max(bi,ans[ac[j].w]);
		}
	}
}
int main()
{
	while(scanf("%d",&n)==1&&n!=0)
	{
		memset(&ac,0,sizeof ac);
		bi=0;
		memset(ans,0,sizeof ans);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",str[i]);
			add(str[i],i);
		}
		make();scanf("%s",mu);
		acm(mu);
		printf("%d\n",bi);
		for(int i=1;i<=n;i++)
		if(ans[i]==bi) cout<<str[i]<<endl;
	}
	return 0;
}
