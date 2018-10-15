#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=30;
int x,y,s[maxn],f[maxn][11][2][2];
int dp(int w,int n,bool up,bool o)
{
	if(w==1)return 1;
	if(~f[w][n][up][o])return f[w][n][up][0];
	f[w][n][up][o]=0;
	int upp=up?s[w-1]:9;
	for(int i=0;i<=upp;i++)
	if(abs(i-n)>=2||o)//根据题意 
	f[w][n][up][o]+=dp(w-1,i,up&(i==upp),o&(!i));
	return f[w][n][up][o];
}
int solve(int a)
{
	int ans=0,w=0;
	do{
		s[++w]=a%10;
		a/=10;
	}while(a);//很有必要,存在a==0的情况 
	memset(f,-1,sizeof f);
	for(int i=0;i<=s[w];i++)
	ans+=dp(w,i,i==s[w],(!i));
	return ans;
}
int main()
{
	scanf("%d%d",&x,&y);
	printf("%d\n",solve(y)-solve(x-1));
	return 0;
}
