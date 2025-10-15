#include<iostream>

using namespace std;
typedef long long LL;
const int N=1e5+10;
struct Node
{
    int s[2],p,v;
    int sz;
    LL sum;
    int add;

    void init(int _p,int _v)
    {
        p=_p,v=_v;
        sz=1;
        sum=_v;
    }

}tr[N];
int w[N];
int root,idx;
int n,m;

void pushup(int u)
{
    tr[u].sz=tr[tr[u].s[0]].sz+tr[tr[u].s[1]].sz+1;
    tr[u].sum=tr[tr[u].s[0]].sum+tr[tr[u].s[1]].sum+tr[u].v;
}

void pushdown(int u)
{
    if(tr[u].add)
    {
        tr[tr[u].s[0]].add+=tr[u].add;
        tr[tr[u].s[1]].add+=tr[u].add;
        tr[tr[u].s[0]].v+=tr[u].add;
        tr[tr[u].s[1]].v+=tr[u].add;
        tr[tr[u].s[0]].sum+=(LL)tr[u].add*tr[tr[u].s[0]].sz;
        tr[tr[u].s[1]].sum+=(LL)tr[u].add*tr[tr[u].s[1]].sz;
        tr[u].add=0;
    }
}

int build(int l,int r,int p)
{
    int mid=l+r>>1;
    int u=++idx;
    tr[u].init(p,w[mid]);
    if(l<mid) tr[u].s[0]=build(l,mid-1,u);
    if(r>mid) tr[u].s[1]=build(mid+1,r,u);
    pushup(u);
    return u;
}

void rotate(int x)
{
    int y=tr[x].p,z=tr[y].p;
    int k=tr[y].s[1]==x;
    tr[z].s[tr[z].s[1]==y]=x,tr[x].p=z;
    tr[y].s[k]=tr[x].s[k^1],tr[tr[x].s[k^1]].p=y;
    tr[x].s[k^1]=y,tr[y].p=x;
    pushup(y),pushup(x);
}

void splay(int x,int k)
{
    while(tr[x].p!=k)
    {
        int y=tr[x].p,z=tr[y].p;
        if(z!=k)
            if((tr[z].s[0]==y)^(tr[y].s[0]==x)) rotate(x);
            else rotate(y);
        rotate(x);
    }
    if(!k) root=x;
}

int get_k(int k)
{
    int u=root;
    while(u)
    {
        pushdown(u);
        if(k<=tr[tr[u].s[0]].sz) u=tr[u].s[0];
        else if(k==tr[tr[u].s[0]].sz+1) return u;
        else k-=tr[tr[u].s[0]].sz+1,u=tr[u].s[1];
    }
    return -1;
}


int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&w[i]);

    root=build(0,n+1,0);

    char op[2];
    int l,r,d;
    while(m--)
    {
        scanf("%s%d%d",op,&l,&r);
        l=get_k(l),r=get_k(r+2);
        splay(l,0),splay(r,l);
        if(op[0]=='Q') printf("%lld\n",tr[tr[r].s[0]].sum);
        else
        {
            scanf("%d",&d);
            tr[tr[r].s[0]].v+=d;
            tr[tr[r].s[0]].add+=d;
            tr[tr[r].s[0]].sum+=(LL)tr[tr[r].s[0]].sz*d;
            pushup(r), pushup(l);
        }
    }


    return 0;
}