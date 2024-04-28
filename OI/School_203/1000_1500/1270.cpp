#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int A[N],B[N],C[N],cnt[1<<17],n;
void QuickSort(int L,int R)
{
	if(R<=L)return ;
	int key=A[rand()%(R-L+1)+L];
	int i=L,j=R;
	while(i<=j)
	{
		while(A[i]<key)++i;
		while(A[j]>key)--j;
		if(i<=j)swap(A[i++],A[j--]);
	}
	QuickSort(L,j);
	QuickSort(i,R);
}
void MergeSort(int L,int R)
{
	if(R<=L)return ;
	int mid=L+R>>1;
	MergeSort(L,mid);
	MergeSort(mid+1,R);
	int k=L-1,i=L,j=mid+1;
	for(; i<=mid&&j<=R;)
		if(A[i]<=A[j])B[++k]=A[i++];
		else B[++k]=A[j++];
	while(i<=mid)B[++k]=A[i++];
	while(j<=R)B[++k]=A[j++];
	for(int p=L; p<=R; ++p)A[p]=B[p];
}
void RadixSort()
{
	int m=(1<<16)-1;
	for(int i=1; i<=n; ++i)++cnt[A[i]&m];
	for(int i=1; i<=m; ++i)cnt[i]+=cnt[i-1];
	for(int i=n; i>=1; --i)B[cnt[A[i]&m]--]=i;
	memset(cnt,0,sizeof cnt);
	for(int i=1; i<=n; ++i)++cnt[A[B[i]]>>16&m];
	for(int i=1; i<=m; ++i)cnt[i]+=cnt[i-1];
	for(int i=n; i>=1; --i)C[cnt[A[B[i]]>>16&m]--]=B[i];
	for(int i=1; i<=n; ++i)B[i]=A[C[i]];
	for(int i=1; i<=n; ++i)A[i]=B[i]-1e9;
}
void ShellSort()
{
	for(int len=n>>1;len;len>>=1)
		for(int i=len;i<=n;++i)
			for(int j=i-len;j>=1&&A[j]>A[j+len];j-=len)
				swap(A[j],A[j+len]);
}
void InsertSort()
{
	for(int i=1;i<=n;++i)
	{
		for()
	}
}
int main()
{
	cin>>n;
	for(int i=1; i<=n; ++i)
		scanf("%d",&A[i]);
	// QuickSort(1,n);
	// MergeSort(1,n);
	// RadixSort();
	ShellSort();
	for(int i=1; i<=n; ++i)
		printf("%d ",A[i]);
}