#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
const int N=5e5+10,M=N*2,K=20;
int h[N],e[M],ne[M],idx;
int dep[N],fa[N],dfn[N],dln[N];
int U[N]; // U[i]=u 欧拉序为i的节点编号是u
int lg[N];
struct Node
{
    int depth,x;
    bool operator < (const Node& t) const
    {
        return depth<t.depth;
    }
}f[N][K];
int n,q,root;

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int timestamp;
void dfs(int u,int father,int depth)
{
    fa[u]=father;
    dfn[u]=++timestamp;
    U[dfn[u]]=u;
    dep[dfn[u]]=depth;
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(j==father) continue;
        dfs(j,u,depth+1);
    }
    dln[u]=timestamp;
}

void rmq()
{
    for(int j=0;j<K;j++)
       for(int i=1;i+(1<<j)-1<=n;i++)
          if(!j) f[i][j]={dep[i],U[i]};
          else f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
}

int query(int l,int r)
{
    int len=r-l+1;
    int k=lg[len];
    return min(f[l][k],f[r-(1<<k)+1][k]).x;
}

int lca(int u,int v)
{
    if(dfn[u]>dfn[v]) swap(u,v);
    if(dfn[u]<=dfn[v]&&dfn[v]<=dln[u]) return u;
    return fa[query(dfn[u],dfn[v])];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    lg[1]=0;
    for(int i=2;i<N;i++) lg[i]=lg[i/2]+1;

    memset(h,-1,sizeof h);
    cin>>n>>q>>root;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }

    dfs(root,-1,1);
    rmq();

    while(q--)
    {
        int u,v;
        cin>>u>>v;
        cout<<lca(u,v)<<'\n';
    }

    return 0;
}
