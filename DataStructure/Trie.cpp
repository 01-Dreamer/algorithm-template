#include<iostream>

using namespace std;
const int N=1e5+10;
int tr[N][26],cnt[N],idx;

void insert(char str[])
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int t=str[i]-'a';
        if(!tr[p][t]) tr[p][t]=++idx;
        p=tr[p][t];
    }
    cnt[p]++;
}

int query(char str[])
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int t=str[i]-'a';
        if(!tr[p][t]) return 0;
        p=tr[p][t];
    }
    return cnt[p];
}


int main()
{
    int T;
    scanf("%d",&T);
    
    char op[2],str[N];
    while(T--)
    {
        scanf("%s%s",op,str);
        if(op[0]=='I') insert(str);
        else printf("%d\n",query(str));
    }


    return 0;
}
