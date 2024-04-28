import os
rep=input()
files = os.listdir(os.getcwd())
for file in files:
    if len(file)>=2 and file[:2]==rep[:2]:
        continue
    if (file[0]).isalpha() and file[-3:]=="cpp" and file[1]=='_' :
        x=file[0]
        i=2
        while True:
            if not file[i].isdigit():
                break
            x+=file[i]
            i+=1
        x=rep+x+".cpp"
        os.rename(file,x)
        print(x)
