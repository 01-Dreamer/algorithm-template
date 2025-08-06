#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef __int128_t int128;

LL qmi(LL a,LL n,LL p)
{
    LL res=1;
    while(n)
    {
        if(n&1) res=((int128)res*a)%p;
        a=((int128)a*a)%p;
        n>>=1;
    }
    return res;
}

LL Base[7]={2,325,9375,28178,450775,9780504,1795265022};
bool miller_rabin(LL x)
{
    if(x<3) return x == 2;
    if (x%2==0) return false;

    LL d =x-1,r=0;
    while(d%2==0)d/=2,r++;
    for (LL a:Base)
    {
        LL v=qmi(a, d, x);
        if (v<=1||v==x-1) continue;
        for (int i=0;i<r;i++)
        {
            v=(int128)v*v%x;
            if (v==x-1&&i!=r-1)
            {
                v=1;
                break;
            }
            if(v==1) return false;
        }
        if(v!=1) return false;
    }
    return true;
}

void solve()
{
    LL n;
    cin>>n;
    if(miller_rabin(n)) cout<<"Yes"<<'\n';
    else cout<<"No"<<'\n';
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T=1;
    cin>>T;
    while(T--) solve();

    return 0;
}
