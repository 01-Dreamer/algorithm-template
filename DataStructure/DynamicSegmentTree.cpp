#include<iostream>

using namespace std;
typedef long long LL;
const int N=1e5+10;

struct Node
{
    int ls, rs; 
    LL sum, add;
}tr[N*40]; 

int n,m;
int w[N];
int root, idx;

void pushup(int u)
{
    tr[u].sum = tr[tr[u].ls].sum + tr[tr[u].rs].sum;
}

void pushdown(int u, int pl, int pr)
{
    if(tr[u].add)
    {
        if(!tr[u].ls) tr[u].ls = ++idx;
        if(!tr[u].rs) tr[u].rs = ++idx;
        
        int mid = (pl + pr) >> 1;
        Node &left = tr[tr[u].ls], &right = tr[tr[u].rs];
        
        left.add += tr[u].add;
        left.sum += (LL)(mid - pl + 1) * tr[u].add;
        right.add += tr[u].add;
        right.sum += (LL)(pr - mid) * tr[u].add;
        tr[u].add = 0;
    }
}

void modify(int &u, int pl, int pr, int l, int r, int d)
{
    if(!u) u = ++idx;
    
    if(l <= pl && pr <= r)
    {
        tr[u].sum += (LL)(pr - pl + 1) * d;
        tr[u].add += d;
        return;
    }
    
    pushdown(u, pl, pr);
    int mid = (pl + pr) >> 1;
    
    if(l <= mid) modify(tr[u].ls, pl, mid, l, r, d);
    if(r > mid) modify(tr[u].rs, mid + 1, pr, l, r, d);
    
    pushup(u);
}

LL query(int u, int pl, int pr, int l, int r)
{
    if(!u) return 0;
    
    if(l <= pl && pr <= r) return tr[u].sum;
    
    pushdown(u, pl, pr);
    int mid = (pl + pr) >> 1;
    LL sum = 0;
    
    if(l <= mid) sum += query(tr[u].ls, pl, mid, l, r);
    if(r > mid) sum += query(tr[u].rs, mid + 1, pr, l, r);
    
    return sum;
}

int main()
{
    scanf("%d%d",&n,&m);
    
    for(int i=1; i<=n; i++) 
    {
        scanf("%d",&w[i]);
        modify(root, 1, n, i, i, w[i]); 
    }
    
    char op[2];
    int l,r;
    
    while(m--)
    {
        scanf("%s%d%d",op,&l,&r);
        
        if(op[0]=='C')
        {
            int d;
            scanf("%d",&d);
            modify(root, 1, n, l, r, d);
        }
        else 
        {
            printf("%lld\n", query(root, 1, n, l, r));
        }
    }
    
    return 0;
}