#include<cstdio>//合并果子 
#include<algorithm>
#include<queue>
using namespace std;
struct fy
{
	int d;
	bool operator < (const fy a) const {return d>a.d;}
};
priority_queue<fy>q;
fy a,b,he;
int n,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a.d);
		q.push(a);
	}
	while(--n)
	{
		a=q.top();q.pop();
		b=q.top();q.pop();
		he.d=a.d+b.d;
		ans+=he.d;
		q.push(he);
	}
	printf("%d\n",ans);
	return 0;
}
