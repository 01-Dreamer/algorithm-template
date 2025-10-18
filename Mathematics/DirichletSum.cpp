#include <bits/stdc++.h>

#define double long double
using namespace std;
typedef unsigned int u32;
typedef pair<int,int> PII;
const int N=2e7+10;
u32 a[N];
bool st[N];
int n;

#define uint unsigned int
uint seed;
inline uint getnext(){
	seed^=seed<<13;
	seed^=seed>>17;
	seed^=seed<<5;
	return seed;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>seed;
    for(int i=1;i<=n;i++) a[i]=getnext();
    for(int i=2;i<=n;i++)
    {
        if(st[i]) continue;
        for(int j=i,k=1;j<=n;j+=i,k++)
            a[j]+=a[k],st[j]=true;
    }
    u32 res=0;
    for(int i=1;i<=n;i++) res^=a[i];
    cout<<res<<'\n';

    return 0;
}
