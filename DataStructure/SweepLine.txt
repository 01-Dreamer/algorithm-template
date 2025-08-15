// x1 y1 x2 y2  (x1<x2 y1<y2)

#include<iostream>
#include<algorithm>

using namespace std;
const int N=10010;

struct Edge
{
    int x,y1,y2,k;
    
    bool operator < (const Edge& t) const
    {
        return x<t.x;
    }
    
}e[N*2];

struct Node
{
    int l,r;
    int cnt,len;
}tr[N*4];

void pushup(int u)
{
    if(tr[u].cnt>0) tr[u].len=tr[u].r-tr[u].l+1;
    else if(tr[u].l==tr[u].r) tr[u].len=0;
    else tr[u].len=tr[u<<1].len+tr[u<<1|1].len;
}

void build(int u,int l,int r)
{
    tr[u]={l,r};
    if(l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}

void modify(int u,int l,int r,int k)
{
    if(l<=tr[u].l&&tr[u].r<=r)
    {
        tr[u].cnt+=k;
        pushup(u);
    }
    else
    {
        int mid=tr[u].l+tr[u].r>>1;
        if(l<=mid) modify(u<<1,l,r,k);
        if(r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
}

int main()
{
    int T;
    
    scanf("%d",&T);
    
    int m=0;
    int x1,y1,x2,y2;
    while(T--)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        e[m++]={x1,y1,y2,1};
        e[m++]={x2,y1,y2,-1};
    }
    
    sort(e,e+m);
    
    build(1,0,10000);
    
    int res=0;
    for(int i=0;i<m;i++)
    {
        if(i>0) res+=(e[i].x-e[i-1].x)*tr[1].len;
        modify(1,e[i].y1,e[i].y2-1,e[i].k);
    }
    
    printf("%d",res);
    
    return 0;
}

// double version

#include<iostream>
#include<algorithm>
#include<cstring>
#include<unordered_map>

using namespace std;
const int N=10010;
double alls[N*2];

unordered_map<double,int>S;
int idx;

struct Edge
{
    double x,y1,y2;
    int k;
    
    bool operator < (const Edge& t) const
    {
        return x<t.x;
    }
  
}e[N*2];

struct Node
{
    int l,r;
    double len;
    int cnt;
}tr[N*8];

void pushup(int u)
{
    if(tr[u].cnt>0) tr[u].len=alls[tr[u].r+1]-alls[tr[u].l];
    else if(tr[u].l==tr[u].r) tr[u].len=0;
    else tr[u].len=tr[u<<1].len+tr[u<<1|1].len;
}

void build(int u,int l,int r)
{
    tr[u]={l,r};
    if(l==r) return;
    int mid=l+r>>1;
    build(u<<1,l,mid);
    build(u<<1|1,mid+1,r);
}

void modify(int u,int l,int r,int k)
{
    if(l<=tr[u].l&&tr[u].r<=r)
    {
        tr[u].cnt+=k;
        pushup(u);
    }
    else
    {
        int mid=tr[u].l+tr[u].r>>1;
        if(l<=mid) modify(u<<1,l,r,k);
        if(r>mid) modify(u<<1|1,l,r,k);
        pushup(u);
    }
    
}

int main()
{
    int n;
    int T=1;
    while(scanf("%d",&n),n)
    {
        double x1,y1,x2,y2;
        int m=0,k=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            e[m++]={x1,y1,y2,1};
            e[m++]={x2,y1,y2,-1};
            alls[k++]=y1;
            alls[k++]=y2;
        }
        
        sort(e,e+m);
        sort(alls,alls+k);
        k=unique(alls,alls+k)-alls;
        
        S.clear();
        idx=0;
        for(int i=0;i<k;i++) S[alls[i]]=idx++;
        
        
        build(1,0,20000);
        
        double res=0;
        
        for(int i=0;i<m;i++)
        {
            if(i>0) res+=(e[i].x-e[i-1].x)*tr[1].len;
            modify(1,S[e[i].y1],S[e[i].y2]-1,e[i].k);
        }
        printf("Test case #%d\n",T++);
        printf("Total explored area: %.2lf\n\n",res);
    }
    
    
    return 0;
}
