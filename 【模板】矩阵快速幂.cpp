#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long 
using namespace std;
int n,mod;
struct fy{
	ll x[3][3];
}st,a;
void mx(fy &a,fy &b,fy &c){
	memset(c.x,0,sizeof c.x);
	for(int i=1;i<=2;i++)
	for(int j=1;j<=2;j++)
	for(int k=1;k<=2;k++)
	c.x[i][j]=(c.x[i][j]+a.x[i][k]*b.x[k][j]%mod)%mod;
}
int qpow(int b){
	if(b<=0)return 1;
	fy ans=st,t;
	a.x[1][1]=a.x[2][2]=1;
	while(b){
		if(b&1){
			mx(a,ans,t);
			a=t;
		}
		mx(ans,ans,t);
		ans=t;
		b>>=1;
	}
	return a.x[1][1]+a.x[1][2];
}
int main(){
	scanf("%d%d",&n,&mod);
	st.x[1][1]=1;st.x[1][2]=1;
	st.x[2][1]=1;st.x[2][2]=0;
	printf("%d\n",(qpow(n)-1)%mod);
	return 0;
}
