/*
1.定 N 个闭区间 [ai,bi]，请你在数轴上选择尽量少的点，使得每个区间内至少包含一个选出的点（位于区间端点上的点也算作区间内）。
2.给定 N个闭区间 [ai,bi]，请你在数轴上选择若干区间（最大数量），使得选中的区间之间互不相交（包括端点）。
*/


#include <iostream>
#include <algorithm>

using namespace std;
const int N=1e5+10;
struct Node
{
    int l,r;
    
    bool operator < (const Node& t) const
    {
        return r<t.r;
    }
    
}e[N];
int n;


int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>e[i].l>>e[i].r;
    sort(e,e+n);
    
    int res=0,r=-2e9;
    for(int i=0;i<n;i++)
    {
        if(e[i].l>r)
        {
            r=e[i].r;
            res++;
        }
    }
    
    cout<<res<<'\n';
    
    
    return 0;
}


/*
给定 N个闭区间 [ai,bi]，请你将这些区间分成若干组，使得每组内部的区间两两之间（包括端点）没有交集，并使得组数尽可能小。
输出最小组数。
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int N=1e5+10;
struct Node
{
    int l,r;
    
    bool operator < (const Node& t) const
    {
        return l<t.l;
    }
    
}e[N];
int n;


int main()
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>e[i].l>>e[i].r;
    sort(e,e+n);
    
    priority_queue<int,vector<int>,greater<int>> heap;
    for(int i=0;i<n;i++)
    {
        Node t=e[i];
        if(heap.empty()||t.l<=heap.top()) heap.push(t.r);
        else
        {
            heap.pop();
            heap.push(t.r);
        }
    }
    
    cout<<heap.size()<<'\n';
    
    
    return 0;
}


/*
给定 N个区间 [ai,bi]以及一个区间 [s,t]，请你选择尽量少的区间，将指定区间完全覆盖。
输出最少区间数，如果无法完全覆盖则输出 −1。
*/


#include <iostream>
#include <algorithm>

using namespace std;
const int N=1e5+10;
struct Node
{
    int l,r;
    
    bool operator < (const Node& t) const
    {
        return l<t.l;
    }
    
}e[N];
int st,ed;
int n;


int main()
{
    cin>>st>>ed;
    cin>>n;
    for(int i=0;i<n;i++) cin>>e[i].l>>e[i].r;
    sort(e,e+n);
    
    int res=0;
    bool success=false;
    for(int i=0;i<n;i++)
    {
        int j=i,r=-2e9;
        while(j<n&&e[j].l<=st)
        {
            r=max(r,e[j].r);
            j++;
        }
        
        if(r<st) break;
        
        res++;
        if(r>=ed)
        {
            success=true;
            break;
        }
        
        st=r;
        i=j-1;
    }
    
    if(!success) res=-1;
    cout<<res<<'\n';
    
    
    return 0;
}