#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cctype>
#include<queue>
using namespace std;
const int maxn=1e5+10;
int head[maxn],num;
int read()
{
	int x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar());
	for(;isdigit(ch);ch=getchar())
	x=(x<<3)+(x<<1)+ch-48;
	return x;
}
struct fy
{
	int to,d,next;
}q[maxn<<1];
void add(int a,int b,int c)
{
	q[++num]=(fy){b,c,head[a]};head[a]=num;
}
int dis[maxn];
struct ffy
{
	int u,dd;
	bool operator<(const ffy a)const{return dd>a.dd;}
};
priority_queue<ffy>qq;
int n,m,s;
void dj(int a)
{
	memset(dis,0x3f,sizeof dis);
	qq.push((ffy){a,0});dis[a]=0;
	while(!qq.empty())
	{
		int b=qq.top().u,v=qq.top().dd;
		qq.pop();
		if(v!=dis[b]) continue;
		for(int i=head[b];i;i=q[i].next)
		{
			int c=q[i].to;
			if(dis[c]>dis[b]+q[i].d)
			{
				dis[c]=dis[b]+q[i].d;
				qq.push((ffy){c,dis[c]});
			}
		}
	}
}
int main()
{
	n=read(),m=read(),s=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read(),z=read();
		add(x,y,z);
	}
	dj(s);
	for(int i=1;i<=n;i++)
	cout<<dis[i]<<' ';
	return 0;
}
