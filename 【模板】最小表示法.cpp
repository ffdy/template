#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=6e5+10;
int n,l;
char str[maxn];
int main() {
	scanf("%d",&n);
	while(n--) {//jkdasfjaksfdkaskdfask
		scanf("%s",str);
		l=strlen(str);
		int ll=0,rr=1;
		while(ll<l&&rr<l) {
			int i=0;
			while(i<l&&str[(ll+i)%l]==str[(rr+i)%l]) i++;
			if(i>=l) break;
			if(str[(ll+i)%l]>str[(rr+i)%l]) {
				ll=max(rr,ll+1+i);
				rr=ll+1;
			} else rr=rr+i+1;
		}
		printf("%d\n",ll);
	}
//	printf("%d",asdf);
	return 0;
}
