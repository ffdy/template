#include<cstdio>//蜜汁代码 
#include<algorithm>
using namespace std;
int n,son[10001],num=1;
int m,head[10001],w=1,d;
int fa[10001],cnt;
bool used[400090];
struct fy{int to,next;}q[400001];
void add(int a,int b)
{
	q[++num]=(fy){b,head[a]};head[a]=num;
	q[++num]=(fy){a,head[b]};head[b]=num;
}
int find(int a){return fa[a]==a?fa[a]:fa[a]=find(fa[a]);}
void get(int a)
{
  	for(int &i=head[a];i;i=q[i].next)
  	if(!used[i]) used[i]=used[i^1]=true,get(q[i].to);
  	printf("%d ",a);
}
int main()
{
	int size = 25<< 20; //手动开栈 
  	char *x = (char*)malloc(size) + size;
  	__asm__("movl %0, %%esp\n" :: "r"(x));
	scanf("%d%d",&n,&m); cnt=n;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int x=find(a),y=find(b);
    	if(x!=y) {fa[x]=y;cnt--;}
		add(a,b);	
		son[a]++;son[b]++;
	}
	for(int i=1;i<=n;i++)
	if(son[i]==0) cnt--;
	else w=i;
	for(int i=1;i<=n;i++)
	if(son[i]%2==1){d++;w=i;}
	if((d!=0&&d!=2)||cnt!=1)
	{printf("0\n");return 0;}
	printf("1\n");
    get(w);
	return 0;
}

