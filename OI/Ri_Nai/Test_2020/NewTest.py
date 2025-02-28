import os
txt="""#include<bits/stdc++.h>
using namespace std;
#define FCLS() fclose(stdin);fclose(stdout)
#define FILE(s) freopen(s".in","r",stdin);freopen(s".out","w",stdout)
int main()
{
	FILE(XXXX);
	FCLS();
}"""
mypath=os.getcwd();
s=""
os.mkdir(os.path.join(mypath,s))
mypath=os.path.join(mypath,s)
a=input().split()
t=(".in",".cpp")
for name in a:
    os.mkdir(os.path.join(mypath,name))
    for ext in t:
        full_path=os.path.join(mypath,name,name+ext)
        f=open(full_path,'w')
        if ext == ".cpp":
            f.write(txt.replace("XXXX","\""+name+"\""))
        f.close()
