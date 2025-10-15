#include<iostream>
#include<cstring>

using namespace std;
const int N=2e6+10;
int h[N],e[N],ne[N],idx;
int low[N],dfn[N],timestamp;
int id[N],scc_cnt;
int stk[N],top;
bool in_stk[N];
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
        scc_cnt++;
        int y;
        do
        {
            y=stk[top--];
            in_stk[y]=false;
            id[y]=scc_cnt;
        }while(y!=u);
    }
}


int main()
{
    scanf("%d%d",&n,&m);
    
    memset(h,-1,sizeof h);
    while(m--)
    {
        int i,a,j,b;
        scanf("%d%d%d%d",&i,&a,&j,&b);// xi==a  xj==b
        i--,j--;
        add(2*i+!a,2*j+b);
        add(2*j+!b,2*i+a);
    }
    
    for(int i=0;i<2*n;i++)
       if(!dfn[i])
          tarjan(i);
    
    for(int i=0;i<n;i++)
       if(id[2*i]==id[2*i+1])
       {
           puts("IMPOSSIBLE");
           return 0;
       }
    puts("POSSIBLE");
    for(int i=0;i<n;i++)
       if(id[2*i]<id[2*i+1]) printf("0 ");
       else printf("1 ");
    
    
    return 0;
}