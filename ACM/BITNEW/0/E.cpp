#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define End(X) return cout<<X<<'\n',void()
const int n=14*2;
char s[30];
int TO[128];
const char re[3]={'m','p','t'};
namespace T
{
    int cnt[40],num[40],is[3];
    bool lqd()
    {
        for(int i=1;i<=27;++i)
            if(cnt[i]%2!=0)return 0;
        return 1;
    }
    bool ddp()
    {
        int t1=0,t2=0;
        for(int i=1;i<=27;++i)
        {
            if(cnt[i]==3)++t1;
            if(cnt[i]==2)++t2;
        }
        return t1==4 and t2==1;
    }
    bool itl()
    {
        for(int i=0;i<=2;++i)
        {
            bool mark=1;
            for(int j=1;j<=9;++j)
                mark&=cnt[i*9+j]!=0;
            if(mark)return 1;
        }
        return 0;
    }
    int PingHu()
    {
        for(int i=1;i<=27;++i)
        {
            if(cnt[i]>=2)
            {
                cnt[i]-=2;
                for(int j=1;j<=27;++j)
                    num[j]=cnt[j];
                bool flag=1;
                for(int j=1;j<=27;++j)
                {
                    if(num[j]>=3)num[j]-=3;
                    if(num[j])
                    {
                        if((j+1)/9==(j-1)/9 and num[j+1]>=num[j]
                         and num[j+2]>=num[j])num[j+1]-=num[j],
                         num[j+2]-=num[j],num[j]=0;
                        else {flag=0;break;}
                    }
                }
                cnt[i]+=2;
                if(flag)return i;
            }
        }
        return 0;
    }
    string To_s(int i)
    {
        string s;
        s+=(char)(48+(i-1)%9+1);
        s+=re[((i-1)/9)];
        return s;
    }
    void solve()
    {
        memset(cnt,0,sizeof cnt);
        memset(is,0,sizeof is);
        int ans=1;

        for(int i=1;i<=n;i+=2)
            ++cnt[TO[s[i+1]]*9+s[i]-48],is[TO[s[i+1]]]=1;

        //qing
        bool qing=is[0]+is[1]+is[2]==1;
        ans*=qing?4:1;

        bool can=is[0]+is[1]+is[2]==3;

        int gen=0;
        for(int i=1;i<=27;++i)
            if(cnt[i]==4)++gen;
        ans*=1<<gen;
        //lqd
        if(lqd())
        {
            for(int i=1;i<=27;++i)
                if(cnt[i])
                {
                    string s=To_s(i);
                    if(cnt[i]==4)
                        cout<<s+s<<'\n'<<s+s<<'\n';
                    else
                        cout<<s+s<<'\n';
                }

            ans*=4;
            if(can)End("ZhaHu");
            if(qing)cout<<"Qing";
            if(gen)cout<<"Long";
            else if(!qing)cout<<"An";
            cout<<"QiDui"<<" *"<<ans<<'\n';
            return;
        }


        if(ddp())
        {
            ans*=2;
            for(int i=1;i<=27;++i)
                if(cnt[i]==3)
                {
                    string s=To_s(i);
                    cout<<s+s+s<<'\n';
                }
            for(int i=1;i<=27;++i)
                if(cnt[i]==2)
                {
                    string s=To_s(i);
                    cout<<s+s<<'\n';
                }
            if(can)End("ZhaHu");
            if(qing)cout<<"QingYiSe";
            cout<<"DuiDuiHu *"<<ans<<'\n';
            return;
        }


        int res=PingHu();
        if(!res)End("ZhaHu\nHuaZhu");
        else
        {
            bool it=itl();
            if(can)End("ZhaHu");
            cnt[res]-=2;
            for(int i=1;i<=27;++i)
            {
                if(cnt[i]>=3)
                {
                    string s=To_s(i);
                    cout<<s+s+s<<'\n';
                    cnt[i]-=3;
                }
                if(cnt[i])
                {
                    string s1=To_s(i);
                    string s2=To_s(i+1);
                    string s3=To_s(i+2);
                    while(cnt[i])
                    {
                        cout<<s1+s2+s3<<'\n';
                        --cnt[i+1];
                        --cnt[i+2];
                        --cnt[i];
                    }
                }
            }
            string s=To_s(res);
            cout<<s+s<<'\n';
            if(qing)cout<<"QingYiSe";
            if(it)cout<<"YiTiaoLong",ans*=2;
            if(!qing and !it)cout<<"PingHu";
            cout<<" *"<<ans<<'\n';
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    TO['m']=0,TO['p']=1,TO['t']=2;
    while(cin>>s+1)T::solve();

}
