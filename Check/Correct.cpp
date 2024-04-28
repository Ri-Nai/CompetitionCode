#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 5e6 + 10;
int T, n, len[N];
vector<int> ans[N];
char s[M];
struct Node{
	int len, a[26];
	bool operator < (const Node &x) const{
		return len < x.len;
	}
}a[N], st[N];
int top;
bool flag;
Node Mod(Node A, Node B){
	int bs = A.len / B.len; A.len %= B.len;
	for(int i = 0; i < 26; ++i){
		A.a[i] -= bs * B.a[i];
		if(A.a[i] < 0){
			flag = false;
			return A;
		}
	}
	return A;
}
priority_queue<Node> ris;
int main()
{
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i){
			scanf("%s", s);
			len[i] = strlen(s);
			ans[i].resize(len[i] + 3);
			a[i].len = len[i];
			memset(a[i].a, 0, sizeof(a[i].a));
			for(int j = 0; j < len[i]; ++j) a[i].a[s[j] - 'a']++;
		}
		flag = true;
		while(!ris.empty()) ris.pop();
		ris.push(a[n]);
		for(int i = n - 1; i >= 1; --i){
			//aabaab
			//abaa ab
			//abaa
			//对前面进行约束对吧
			//只有大的才会对小的进行约束吗
			//
			//
			//那您这个d不是就浪费掉了吗
			//3
			//abd
			//abcd
			//abc

			while(!ris.empty() && ris.top().len >= a[i].len){
				Node tmp = ris.top(); ris.pop();
				ris.push(Mod(tmp, a[i]));
				if(!flag) break;
			}
			if(!flag) break;
			ris.push(a[i]);
		}
		if(!flag){
			puts("NO");
			continue;
		}
		top = 0;
//		cout << "finish" << endl;
		while(!ris.empty()) st[++top] = ris.top(), ris.pop();
		reverse(st + 1, st + 1 + top);
		for(int i = 2; i <= top; ++i){
			if(st[i].len == st[i - 1].len){
				for(int j = 0; j < 26; ++j) if(st[i].a[j] != st[i - 1].a[j]){flag = false; break;}
			}
		}
		if(!flag){
			puts("NO");
			continue;
		}
		int num = 0;
		for(int i = 1; i <= top; ++i){
			if(st[i].len == st[i - 1].len) continue;
			for(int j = 0; j < 26; ++j){
				if(st[i].a[j] < st[i - 1].a[j]){flag = false; break;}
				for(int k = st[i - 1].a[j] + 1; k <= st[i].a[j]; ++k) ans[1][num++] = j;
			}
		}
		if(!flag){
			puts("NO");
			continue;
		}
		for(int i = 2; i <= n; ++i)
			for(int j = 0; j < len[i]; ++j) ans[i][j] = ans[i - 1][j % len[i - 1]];
		puts("YES");
		for(int i = 1; i <= n; ++i, puts("")){
			for(int j = 0; j < len[i]; ++j) printf("%c", ans[i][j] + 'a');
		}
	}
	return 0;
}
