#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define dd double
using namespace std;
const int maxn=110;
const dd ex=1e-8;//ƤƤ�ľ��� 
int n;dd f[maxn][maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)for(int j=1;j<=n+1;j++)scanf("%lf",&f[i][j]);//����񷽳̶��� 
	for(int i=1;i<=n;i++)
	{
		dd a=f[i][i];
		//αװ��fabs��abs(����ֵ) 
		if(fabs(a)<=ex) 
		{printf("No Solution\n");return 0;}
		//�����ǰaΪ0,�򷽳��޽� ����ԭ��:��a=0ʱ f[i][j]/a= 1.#J(������) 
		for(int j=i;j<=n+1;j++)f[i][j]/=a;
		for(int j=1;j<=n;j++)if(j!=i)
		{
			dd b=f[j][i];
			for(int k=i;k<=n+1;k++)f[j][k]-=f[i][k]*b;
		}
	}
	for(int i=1;i<=n;i++) printf("%.2lf\n",f[i][n+1]);//������λС����� 
	return 0;
}
