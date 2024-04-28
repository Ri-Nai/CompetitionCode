#include<cstdio>
#define Fasdas
void solve()
{
	int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d",a/5+b/10*3+c/2);
}
int main()
{
	#ifndef F
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	#endif
	solve();
	fclose(stdin);
	fclose(stdout);
}
