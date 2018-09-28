#include<cstdio>
#include<cstdlib>
#include<ctime>
using namespace std;
int main()
{
	for(int i=1;i<=1000;i++)
	{
		system("c://...");//Éú³ÉÆ÷ 
		double st=clock();
		system("c://a.exe");
		double ed=clock();
		system("c://b.exe");
		if(system("fc c://a.exe c://b.exe"))
		{
			puts("WA");
			return 0;
		}
		else printf("AC #%d time:%.0lfms\n",i,ed-st);
	}
	return 0;
}
