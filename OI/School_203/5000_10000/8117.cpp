#include<cstdio>
#include<queue>
#define F(i,t,n) for(int i=t;i<=n;++i)
double p[5][25];long long C[25][25];int n;
struct $
{
	double val;long long num;
	bool operator <($ _)const{return val>_.val;}
};
std::priority_queue<$>Q;
void init()
{
	scanf("%d",&n);C[0][0]=1;
	F(i,1,20)
	{
		C[i][0]=1;
		F(j,1,i)C[i][j]=C[i-1][j]+C[i-1][j-1];
	}
	F(i,1,4)
	{
		p[i][0]=1;scanf("%lf",&p[i][1]);
		F(j,2,20)p[i][j]=p[i][j-1]*p[i][1];
	}
	F(i,0,n)F(j,0,n)F(k,0,n)
		if(i+j+k<=n)Q.push(($){p[1][i]*p[2][j]*p[3][k]*p[4][n-i-j-k],C[n][i]*C[n-i][j]*C[n-i-j][k]});
}
int main()
{
	init();double ans=0;
	while(1)
	{
		double x=Q.top().val;
		long long nx=Q.top().num;
		Q.pop();
		if(nx>1)
		{
			if(nx&1)Q.push(($){x,1}),--nx;
			Q.push(($){x+x,nx>>1});ans+=x*nx;
		}
		else
		{
			if(Q.empty())break;
			double y=Q.top().val;
			long long ny=Q.top().num;
			Q.pop();ans+=x+y;
			Q.push(($){x+y,1});
			if(ny>1)Q.push(($){y,ny-1});
		}
	}
	printf("%.6f\n",ans);
}