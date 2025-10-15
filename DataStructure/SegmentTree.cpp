#include<iostream>

using namespace std;
const int N=100010;
struct Node
{
    int l,r,sum;
}tr[N*4];
int w[N];
int n,m;

void pushup(int u)
{
    tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
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

int query(int u,int l,int r)
{
    if(l<=tr[u].l&&tr[u].r<=r) return tr[u].sum;
    
    int sum=0;
    int mid=tr[u].l+tr[u].r>>1;
    if(l<=mid) sum+=query(u<<1,l,r);
    if(r>mid) sum+=query(u<<1|1,l,r);
    return sum;
}

void modify(int u,int x,int v)
{
    if(tr[u].l==tr[u].r) tr[u].sum+=v;
    else
    {
        int mid=tr[u].l+tr[u].r>>1;
        if(x<=mid) modify(u<<1,x,v);
        else modify(u<<1|1,x,v);
        pushup(u);
    }
}


int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);
    
    build(1,1,n);
    
    int op,a,b;
    while(m--)
    {
        scanf("%d%d%d",&op,&a,&b);
        
        if(!op) printf("%d\n",query(1,a,b));
        else modify(1,a,b);
    }
    
    
    return 0;
}