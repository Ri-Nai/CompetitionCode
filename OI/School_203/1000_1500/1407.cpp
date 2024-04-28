#include<cstdio>
#include<algorithm>
const int maxn=2e5+5;
int N,R,Q,S[maxn],W[maxn],id[maxn],T[maxn];
bool cmp(int a,int b)
{
	return S[a]==S[b]?a<b:S[a]>S[b];
}
void merge()
{
	for(int i=1;i<=N;++i)
	{
		const int &L=2*i-1,&R=2*i;
		if(S[id[L]]>S[id[R]])T[i]=id[L],T[N+i]=id[R];
		else T[i]=id[R],T[N+i]=id[L];
	}
	int index=0,p=1,q=N+1;
	while(p<=N||q<=2*N)
	{
		if(p>N||S[T[q]]>S[T[p]]||(S[T[q]]==S[T[p]]&&T[q]<T[p]))id[++index]=T[q++];
		else if(q>2*N||S[T[q]]<S[T[p]]||(S[T[q]]==S[T[p]]&&T[q]>T[p]))id[++index]=T[p++];
	}
	// for(int i=1;i<=2*N;++i)
	// 	printf("|id=%d S=%d W=%d| ",id[i],S[id[i]],W[id[i]]);
	// puts("");
}
void in_put()
{
	scanf("%d%d%d",&N,&R,&Q);
	for(int i=1;i<=2*N;++i)scanf("%d",&S[i]),id[i]=i;
	for(int i=1;i<=2*N;++i)scanf("%d",&W[i]);
	std::sort(id+1,id+2*N+1,cmp);
	// for(int i=1;i<=2*N;++i)
	// 	printf("|id=%d S=%d W=%d| ",id[i],S[id[i]],W[id[i]]);
	// puts("");
}

void Rnd()
{
	for(int i=1;i<=N;++i)
	{
		const int &L=2*i-1,&R=2*i;
		S[id[L]]+=(W[id[L]]>W[id[R]]);
		S[id[R]]+=(W[id[L]]<W[id[R]]);
	}
	merge();
}
int main()
{
	in_put();
	while(R--)Rnd();
	printf("%d\n",id[Q]);
}