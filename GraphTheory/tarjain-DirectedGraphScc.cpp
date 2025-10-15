#include<iostream>
#include<cstring>

using namespace std;
const int N=1e4+10,M=5e4+10;
int h[N],e[M],ne[M],idx;
int low[N],dfn[N],timestamp;
int id[N],sz[N],scc_cnt;
int stk[N],top;
bool in_stk[N];
int dout[N];
int n,m;

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void tarjan(int u)
{
    low[u]=dfn[u]=++timestamp;
    stk[++top]=u,in_stk[u]=true;
    
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        
        if(!dfn[j])
        {
            tarjan(j);
            low[u]=min(low[u],low[j]);
        }
        else if(in_stk[j]) low[u]=min(low[u],dfn[j]);
    }
    
    if(low[u]==dfn[u])
    {
        int y;
        scc_cnt++;
        do
        {
            y=stk[top--];
            in_stk[y]=false;
            id[y]=scc_cnt;
            sz[scc_cnt]++;
        }while(y!=u);
    }
}


int main()
{
    scanf("%d%d",&n,&m);
    
    memset(h,-1,sizeof h);
    int a,b;
    while(m--)
    {
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    
    for(int i=1;i<=n;i++)
       if(!dfn[i])
          tarjan(i);
    
    for(int i=1;i<=n;i++)
       for(int j=h[i];~j;j=ne[j])
        {
            int k=e[j];
            int a=id[i],b=id[k];
            if(a!=b) dout[a]++;
        }
    
    int res=0,total=0;
    for(int i=1;i<=scc_cnt;i++)
       if(!dout[i])
       {
           res+=sz[i];
           if(++total>1)
           {
               res=0;
               break;
           }
       }
    
    printf("%d",res);
    
    
    return 0;
}