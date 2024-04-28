#include<bits/stdc++.h>
using namespace std;
int main()
{
	int now=0;
	do
	{
		printf("%d\n",++now);
		system("Data > Data.in");
		system("Correct < Data.in > Correct.out");
		system("Mine < Data.in > Mine.out");
        system("SP");
	}
	while(system("fc check.out checkok.out")==0);
}
