n=4
minans=10000
ans=[0]*n
now=[0]*n
a=[0]*n
for i in range(n):
    a[i]=list(map(int,input().split()))
    print(a[i])
mark=[False]*n
def dfs(x,res):
    global minans,ans
    if x==n:
        if res<minans:
            minans=res
            ans=now[:]
        return
    for i in range(n):
        if mark[i]==False:
            mark[i]=True
            now[x]=i
            dfs(x+1,res+a[x][i])
            mark[i]=False
dfs(0,0)
print(minans)
print(ans)
