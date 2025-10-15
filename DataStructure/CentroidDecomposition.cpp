int get_size(int u,int father)
{
    if(st[u]) return 0;
    int sz=1;
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(j==father) continue;
        sz+=get_size(j,u);
    }
    return sz;
}

int get_wc(int u,int father,int tot,int& wc)
{
    if(st[u]) return 0;
    int sum=1,ms=0;
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(j==father) continue;
        int t=get_wc(j,u,tot,wc);
        ms=max(ms,t);
        sum+=t;
    }
    ms=max(ms,tot-sum);
    if(ms<=tot/2) wc=u;
    return sum;
}

