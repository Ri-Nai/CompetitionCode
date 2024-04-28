#include<cmath>
#include<cstdio>
#include<algorithm>
int n,T,A,B,x[25][5],y[25][5],t[25];
double dis[105][105],ans=1e9;
double len(double x1,double y1,double x2,double y2)
{
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void Get(int num)
{
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			for(int k=0;k<3;++k)
				if(i!=j&&j!=k)
					if((x[num][i]-x[num][j])*(x[num][k]-x[num][j])+
						(y[num][k]-y[num][j])*(y[num][i]-y[num][j])==0)
					{

						x[num][3]=x[num][k]+x[num][i]-x[num][j];
						y[num][3]=y[num][k]+y[num][i]-y[num][j];
						return;
					}
}
inline int id(int i,int j){return i*4+j;}
inline int X(int id){return x[id/4][id%4];}
inline int Y(int id){return y[id/4][id%4];}
void build()
{
	for(int i=0;i<4*n;++i)
		for(int j=0;j<4*n;++j)
			if(i/4!=j/4)dis[i][j]=len(X(i),Y(i),X(j),Y(j))*T;

}
int main()
{
	scanf("%d%d%d%d",&n,&T,&A,&B);
	if(A==B){puts("0.0");return 0;};
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<3;++j)
			scanf("%d%d",&x[i][j],&y[i][j]);
		Get(i);scanf("%d",&t[i]);
		for(int j=0;j<4;++j)
			for(int k=j+1;k<4;++k)
			{
				dis[id(i,j)][id(i,k)]=
				dis[id(i,k)][id(i,j)]=
				len(x[i][j],y[i][j],x[i][k],y[i][k])*t[i];
			}
	}
	build();
	for(int k=0;k<4*n;++k)
		for(int i=0;i<4*n;++i)
			for(int j=0;j<4*n;++j)
					dis[i][j]=std::min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=0;i<4;++i)
		for(int j=0;j<4;++j)
				ans=std::min(ans,dis[id(A-1,i)][id(B-1,j)]);
	printf("%.1lf\n",ans);

}