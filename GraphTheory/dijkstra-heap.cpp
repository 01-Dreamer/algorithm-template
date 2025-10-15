#include<iostream>
#include<cstring>
#include<queue>

#define x first
#define y second

using namespace std;
typedef pair<int,int> PII;
const int N=2e5+10;
int h[N],e[N],ne[N],w[N],idx;
int dist[N];
bool st[N];
int n,m;

void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    
    priority_queue<PII,vector<PII>,greater<PII>>q;
    q.push({0,1});
    
    while(!q.empty())
    {
        PII t=q.top();
        q.pop();
        
        int ver=t.y,ds=t.x;
        if(st[ver]) continue;
        st[ver]=true;
        
        for(int i=h[ver];~i;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[ver]+w[i])
            {
                dist[j]=dist[ver]+w[i];
                q.push({dist[j],j});
            }
        }
    }
}


int main()
{
    scanf("%d%d",&n,&m);
    
    int a,b,c;
    memset(h,-1,sizeof h);
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    
    dijkstra();
    printf("%d",dist[n]==0x3f3f3f3f?-1:dist[n]);
    
    
    return 0;
}