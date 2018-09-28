int read()
{
	int x=0;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar());
	for(;isdigit(ch);ch=getchar())
	x=(x<<3)+(x<<1)+ch-48;
	return x;
} 
