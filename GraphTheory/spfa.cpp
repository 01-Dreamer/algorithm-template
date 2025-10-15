#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int N=100010,M=100010;
int h[N],e[M],ne[M],w[M],idx;
int dist[N];
bool st[N];
int n,m;

void add(int a,int b,int c)
{
    e[idx]=b,w[idx]=c,ne[idx]=h[a],h[a]=idx++;
}

void spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    
    queue<int>q;
    q.push(1);
    st[1]=true;
    
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        st[t]=false;
        
        for(int i=h[t];~i;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[t]+w[i])
            {
                dist[j]=dist[t]+w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j]=true;
                }
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
    
    spfa();
    if(dist[n]==0x3f3f3f3f) puts("impossible");
    else printf("%d",dist[n]);


    return 0;
}