#include <bits/stdc++.h>

#define int long long
#define ld long double
using namespace std;
typedef pair<int,int> PII;
const int N=4e5+10,INF=1e18;
struct Node
{
    int x,y;
    bool operator < (const Node& t) const
    {
        if(x!=t.x) return x<t.x;
        return y<t.y;
    }
}p[N],tmp[N];
int n;

int get_dist(Node a,Node b)
{
    int dx=a.x-b.x,dy=a.y-b.y;
    return dx*dx+dy*dy;
}

bool cmp(Node a,Node b)
{
    if(a.y!=b.y) return a.y<b.y;
    return a.x<b.x;
}

int dfs(int l,int r)
{
    if(l>=r) return INF;
    int mid=l+r>>1;
    int mid_x=p[mid].x;
    int res=min(dfs(l,mid),dfs(mid+1,r));

    {
        int i=l,j=mid+1,k=0;
        while(i<=mid&&j<=r)
            if(p[i].y<p[j].y) tmp[k++]=p[i++];
            else tmp[k++]=p[j++];

        while(i<=mid) tmp[k++]=p[i++];
        while(j<=r) tmp[k++]=p[j++];

        for(i=0,j=l;i<k;i++,j++) p[j]=tmp[i];
    }

    int k=0;
    for(int i=l;i<=r;i++)
        if((p[i].x-mid_x)*(p[i].x-mid_x)<res)
            tmp[k++]=p[i];
    for(int i=0;i+1<k;i++)
        for(int j=i+1;j<k&&(tmp[j].y-tmp[i].y)*(tmp[j].y-tmp[i].y)<res;j++)
            res=min(res,get_dist(tmp[i],tmp[j]));

    return res;
}

void solve()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
    sort(p,p+n);
    cout<<dfs(0,n-1)<<'\n';
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
