#include<iostream>
#include<unordered_set>
#include<cstring>

using namespace std;
const int N=110,M=10010;
int s[N],f[M];
int n,k;

int sg(int x)
{
    if(f[x]!=-1) return f[x];
    
    unordered_set<int>S;
    for(int i=0;i<k;i++)
       if(x>=s[i])
          S.insert(sg(x-s[i]));
    
    for(int i=0;;i++)
       if(!S.count(i))
          return f[x]=i;
}


int main()
{
    cin>>k;
    for(int i=0;i<k;i++) cin>>s[i];
    
    memset(f,-1,sizeof f);
    cin>>n;
    int res=0;
    int x;
    while(n--)
    {
        cin>>x;
        res^=sg(x);
    }
    
    if(res) puts("Yes");
    else puts("No");
    
    
    return 0;
}