#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
const int N=5e5+10,M=4e6+10;
int h[N],e[M],ne[M],idx;
int low[N],dfn[N],timestamp;
int id[N],dcc_cnt;
int stk[N],top;
vector<int>dcc[N];
bool cut[N];
int n,m;

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int root;
void tarjan(int u)
{
    low[u]=dfn[u]=++timestamp;
    stk[++top]=u;

    if(u==root&&h[u]==-1)
    {
        dcc_cnt++;
        dcc[dcc_cnt].push_back(u);
        return;
    }

    int cnt=0;
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(!dfn[j])
        {
            tarjan(j);
            low[u]=min(low[u],low[j]);
            if(dfn[u]<=low[j])
            {
                cnt++;
                if(u!=root||cnt>1) cut[u]=true;
                dcc_cnt++;
                int y;
                do
                {
                    y=stk[top--];
                    id[y]=dcc_cnt;
                    dcc[dcc_cnt].push_back(y);
                }while(y!=j);
                dcc[dcc_cnt].push_back(u);
            }
        }
        else low[u]=min(low[u],dfn[j]);
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
        if(a!=b)
        {
            add(a,b);
            add(b,a);
        }
    }

    for(root=1;root<=n;root++)
       if(!dfn[root])
          tarjan(root);

    printf("%d\n",dcc_cnt);

    for(int i=1;i<=dcc_cnt;i++)
    {
        printf("%d ",dcc[i].size());
        for(int v:dcc[i]) printf("%d ",v);
        puts("");
    }
    
    return 0;
}