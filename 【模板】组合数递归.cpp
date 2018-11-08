#include<iostream>
#include<cstdio>
using namespace std;
long long comb(int m,int n) {
	if(n==0) return 1;
	if(n==1) return m;
	if(n>m/2) return comb(m,m-n);
	if(n>1) return (comb(m-1,n-1)+comb(m-1,n));
}
int main() {
	int m,n;
	while(cin>>m>>n)
		cout<<comb(m,n)<<endl;
	return 0;
}
