#include<iostream>
#include<cstring>
#include<queue>

using namespace std;
const int N=5e5+10,M=1e6+10;
int tr[N][26],cnt[N],idx;
int ne[N];

void insert(char str[])
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'a';
        if(!tr[p][u]) tr[p][u]=++idx;
        p=tr[p][u];
    }
    cnt[p]++;
}

void build()
{
    queue<int>q;
    for(int i=0;i<26;i++)
       if(tr[0][i])
          q.push(tr[0][i]);
    
    while(!q.empty())
    {
        int t=q.front();
        q.pop();
        
        for(int i=0;i<26;i++)
        {
            int p=tr[t][i];
            if(p)
            {
                ne[p]=tr[ne[t]][i];
                q.push(p);
            }
            else tr[t][i]=tr[ne[t]][i];
        }
    }
}


int main()
{
    int T;
    scanf("%d",&T);
    
    while(T--)
    {
        idx=0;
        memset(tr,0,sizeof tr);
        memset(cnt,0,sizeof cnt);
        memset(ne,0,sizeof ne);
        
        int n;
        scanf("%d",&n);
        
        char p[N],s[M];
        while(n--)
        {
            scanf("%s",p);
            insert(p);
        }
        
        build();
        
        scanf("%s",s);
        
        int res=0;
        for(int i=0,j=0;s[i];i++)
        {
            int u=s[i]-'a';
            j=tr[j][u];
            
            int p=j;
            while(p&&cnt[p]!=-1)
            {
                res+=cnt[p];
                cnt[p]=-1;
                p=ne[p];
            }
        }
        
        printf("%d\n",res);
    }
    
    
    return 0;
}