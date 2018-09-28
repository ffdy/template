#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,s,num;
bool used[100010];
int head[100010],l[100010];

struct edge{
    int last,to,dis;
}d[500010];

struct node{
    int dis,to;
    bool operator < (const node &a) const
    {
        return dis>a.dis;
    }
};
priority_queue<node>q;

void read(int &x)
{
    x=0;int f=1;char s=getchar();
    while(s<'0'||s>'9') {if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9') {x=x*10+s-'0';s=getchar();}
}

void add(int from,int to,int dis)
{
    d[++num].last=head[from];
    d[num].to=to;
    d[num].dis=dis;
    head[from]=num;
}

int main()
{
    read(n);read(m);read(s);
    int u,v,w;
    for(int i=1;i<=m;i++)
    {
        read(u);
        read(v);
        read(w);
        add(u,v,w);
    }
    memset(l,0x3f,sizeof(l));
    l[1]=0;
    used[1]=1;
    q.push(node{0,1});
    while(!q.empty())
    {
        node p=q.top();q.pop();
        int u=p.to;used[u]=0;
        for(int t=head[u];t;t=d[t].last)
        {
            int v=d[t].to;
            if(l[v]>l[u]+d[t].dis)
            {
                l[v]=l[u]+d[t].dis;
                if(!used[v])
                {
                    used[v]=1;
                    q.push(node{l[v],v});
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    printf("%d ",l[i]);
    return 0;
}

