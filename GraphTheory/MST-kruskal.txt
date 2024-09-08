#include<iostream>
#include<algorithm>

using namespace std;
const int N=2e5+10;
struct Node
{
    int a,b,w;
    
    bool operator < (const Node& t) const
    {
        return w<t.w;
    }
    
}e[N];
int p[N];
int n,m;

int find(int x)
{
    if(x!=p[x]) p[x]=find(p[x]);
    return p[x];
}

int kruskal()
{
    int res=0,cnt=0;
    for(int i=0;i<m;i++)
    {
        int a=e[i].a,b=e[i].b,w=e[i].w;
        
        a=find(a),b=find(b);
        if(a!=b)
        {
            p[a]=b;
            res+=w;
            cnt++;
        }
    }
    
    if(cnt<n-1) return 0x3f3f3f3f;
    return res;
}


int main()
{
    scanf("%d%d",&n,&m);
    
    for(int i=1;i<=n;i++) p[i]=i;
    
    int a,b,w;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&w);
        e[i]={a,b,w};
    }
    
    sort(e,e+m);
    
    int t=kruskal();
    if(t!=0x3f3f3f3f) printf("%d",t);
    else puts("impossible");
    
    
    return 0;
}