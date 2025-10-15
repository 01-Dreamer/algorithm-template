#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;
typedef pair<int,int> PII;
const int N=2e5+10;
int w[N],cnt[N],tot[N];
bool st[N];
int n,m,len;
int get(int i)
{
    return i/len;
}

struct Node
{
    int l,r,id;
    bool operator < (const Node& t) const
    {
        int id1=get(l),id2=get(t.l);
        if(id1!=id2) return id1<id2;
        return r<t.r;
    }
}Q[N];
int res[N];

void add(int x)
{
    if(tot[x]==0) st[x]=false,cnt[get(x)]--;
    tot[x]++;
}

void del(int x)
{
    tot[x]--;
    if(tot[x]==0) st[x]=true,cnt[get(x)]++;
}

int query()
{
    int b=0;
    while(!cnt[b]) b++;
    for(int i=b*len;;i++)
        if(st[i]) return i;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    len=sqrt(N-1);
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=0;i<N;i++) st[i]=true,cnt[get(i)]++;
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        Q[i]={l,r,i};
    }
    sort(Q,Q+m);

    int L=1,R=1;
    add(w[1]);
    for(int i=0;i<m;i++)
    {
        int l=Q[i].l,r=Q[i].r,id=Q[i].id;
        while(L<l) del(w[L++]);
        while(L>l) add(w[--L]);
        while(R<r) add(w[++R]);
        while(R>r) del(w[R--]);
        res[id]=query();
    }
    for(int i=0;i<m;i++) cout<<res[i]<<'\n';

    return 0;
}
