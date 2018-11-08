#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=110;
int n,m,p,a[maxn][maxn],b[maxn][maxn],c[maxn][maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d",&p);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=p;j++){
			scanf("%d",&b[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=p;j++)
			for(int k=1;k<=m;k++) 
				c[i][j]+=a[i][k]*b[k][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=p;j++){
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
