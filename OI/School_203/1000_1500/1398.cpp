#include<string>
#include<iostream>
using namespace std;

string in,post;

void dfs(string in,string post)
{
	if(in.size())
	{
		cout.put(*post.rbegin());
		int mid=in.find(*post.rbegin());
		dfs(in.substr(0,mid),post.substr(0,mid));
		dfs(in.substr(mid+1),post.substr(mid,post.size()-mid-1));
	}
}

int main()
{
	cin>>in>>post;
	dfs(in,post);
}