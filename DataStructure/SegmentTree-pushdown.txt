#include<iostream>

using namespace std;
typedef long long LL;
const int N=1e5+10;
struct Node
{
    int l,r;
    LL sum;
    int add;
}tr[N*4];
int w[N];
int n,m;

void pushup(int u)
{
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
}

void pushup(Node& root,Node& left,Node& right)
{
    root.sum=left.sum+right.sum;
}

void pushdown(int u)
{
    Node& root=tr[u],&left=tr[u<<1],&right=tr[u<<1|1];
    if(root.add)
    {
        left.add+=root.add,right.add+=root.add;
        left.sum+=(LL)(left.r-left.l+1)*root.add;
        right.sum+=(LL)(right.r-right.l+1)*root.add;
        root.add=0;
    }
}

void build(int u,int l,int r)
{
    if(l==r) tr[u]={l,r,w[r]};
    else
    {
        tr[u]={l,r};
        int mid=l+r>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
}

Node query(int u,int l,int r)
{
    if(l<=tr[u].l&&tr[u].r<=r) return tr[u];
    
    pushdown(u);
    int mid=tr[u].l+tr[u].r>>1;
    if(r<=mid) return query(u<<1,l,r);
    if(l>mid) return query(u<<1|1,l,r);
    
    Node res;
    Node left=query(u<<1,l,r);
    Node right=query(u<<1|1,l,r);
    pushup(res,left,right);
    return res;
}

void modify(int u,int l,int r,int d)
{
    if(l<=tr[u].l&&tr[u].r<=r)
    {
        tr[u].sum+=(LL)(tr[u].r-tr[u].l+1)*d;
        tr[u].add+=d;
    }
    else
    {
        pushdown(u);
        int mid=tr[u].l+tr[u].r>>1;
        if(l<=mid) modify(u<<1,l,r,d);
        if(r>mid) modify(u<<1|1,l,r,d);
        pushup(u);
    }
}


int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    
    build(1,1,n);
    
    char op[2];
    int l,r,d;
    while(m--)
    {
        scanf("%s%d%d",op,&l,&r);
        if(op[0]=='Q') printf("%lld\n",query(1,l,r).sum);
        else
        {
            scanf("%d",&d);
            modify(1,l,r,d);
        }
    }
    
    
    return 0;
}
