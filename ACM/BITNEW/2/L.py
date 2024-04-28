n=int(input())
a=map(float,input().split())
res=0
for i in a:
    res+=pow(i,3)
print(pow(res,1/3))
