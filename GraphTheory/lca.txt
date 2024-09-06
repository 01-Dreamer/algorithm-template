#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int N=1e4+10,M=2e4+10;
int h[N],e[M],ne[M],w[M],idx;
int depth[N],fa[N][14],dist[N][14];
int n,m;

void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

int root=1;
void bfs()
{
    memset(depth,0x3f,sizeof depth);
    depth[0]=0,depth[root]=1;
    
    queue<int>q;
    q.push(root);
    
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        
        for(int i=h[t];~i;i=ne[i])
        {
            int j=e[i];
            
            if(depth[j]>depth[t]+1)
            {
                depth[j]=depth[t]+1;
                
                fa[j][0]=t;
                dist[j][0]=w[i];
                
                for(int k=1;k<=13;k++)
                {
                    fa[j][k]=fa[fa[j][k-1]][k-1];
                    dist[j][k]=dist[j][k-1]+dist[fa[j][k-1]][k-1];
                }
                
                q.push(j);
            }
        }
    }
}

int lca(int a,int b)
{
    int res=0;
    if(depth[a]<depth[b]) swap(a,b);
    
    for(int k=13;k>=0;k--)
       if(depth[fa[a][k]]>=depth[b])
       {
           res+=dist[a][k];
           a=fa[a][k];
       }
       
    if(a==b) return res;
    
    for(int k=13;k>=0;k--)
       if(fa[a][k]!=fa[b][k])
       {
           res+=dist[a][k]+dist[b][k];
           a=fa[a][k];
           b=fa[b][k];
       }
    
    return res+dist[a][0]+dist[b][0];   
}


int main()
{
    scanf("%d%d",&n,&m);
    
    memset(h,-1,sizeof h);
    int a,b,c;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c),add(b,a,c);
    }
    
    bfs();
    
    while(m--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",lca(a,b));
    }
    
    
    return 0;
}