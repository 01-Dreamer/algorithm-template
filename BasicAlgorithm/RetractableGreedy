#include <bits/stdc++.h>

#define int long long
#define ld long double
using namespace std;
typedef pair<int,int> PII;


void solve()
{
    int n;
    cin>>n;

    int res=0;
    priority_queue<int,vector<int>,greater<int>> q;
    while(n--)
    {
        int x;
        cin>>x;
        if(!q.empty()&&q.top()<x)
        {
            int t=q.top();
            q.pop();
            q.push(x); // 反悔
            res+=x-t;
        }
        q.push(x); // 交易
    }
    cout<<res<<'\n';
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T=1;
    //cin>>T;
    while(T--) solve();

    return 0;
}

