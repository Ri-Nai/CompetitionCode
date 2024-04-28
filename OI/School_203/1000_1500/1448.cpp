#include<queue>
#include<cstdio>
#include<string>
#include<iostream>
#include<hash_map>
using std::string;
using namespace std;
string A[2][7],S1,S2;
hash_map<string,int>m[2];
struct ${string s;int step;};
int tot;
std::queue<$>Q[2];
int work(int id)
{
	if(!Q[id].empty())
	{
		string now=Q[id].front().s;
		int step=Q[id].front().step;
		Q[id].pop();
		if(step<=5)for(int k=0;k<tot;++k)
		{
			int len=A[id][k].size();
			for(int i=0;i+len<=now.size();++i)
				if(now.substr(i,len)==A[id][k])
				{
					string tmp=now;tmp.replace(i,len,A[id^1][k]);
					if(m[id^1][tmp])return step+1+m[id^1][tmp];
					if(!m[id][tmp])m[id][tmp]=step+1,Q[id].push(($){tmp,step+1});
					
				}
		}
	}
	return 0;

}
int bfs()
{
	Q[0].push(($){S1,0});m[0][S1]=0;
	Q[1].push(($){S2,0});m[1][S2]=0;
	while(!Q[0].empty()||!Q[1].empty())
	{
		int a1=work(0),a2=work(1);
		if(a1)return a1;
		if(a1)return a2;
	}
	return -1;
}
int main()
{
	std::cin>>S1>>S2;
	while(std::cin>>A[0][tot]>>A[1][tot])++tot;
	int k=bfs();
	if(~k)printf("%d\n",k);else puts("NO ANSWER!");
}