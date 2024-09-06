#include<iostream>
#include<cstring>

using namespace std;
const int N=100010;
int e[N],l[N],r[N],idx;
int n;

//在节点 a 的右边插入一个数x
void insert(int a,int x)
{
    e[idx]=x;
    l[idx]=a,r[idx]=r[a];
    l[r[a]]=idx,r[a]=idx++;
}

void remove(int a)
{
    r[l[a]]=r[a];
    l[r[a]]=l[a];
}


int main()
{
    r[0]=1,l[1]=0;
    idx=2;
    
    scanf("%d",&n);
    
    char op[3];
    int k,x;
    while(n--)
    {
        scanf("%s",op);
        
        if(op[0]=='L')//在链表的最左端插入数 x
        {
            scanf("%d",&x);
            insert(0,x);
        }
        else if(op[0]=='R')//在链表的最右端插入数 x
        {
            scanf("%d",&x);
            insert(l[1],x);
        }
        else if(op[0]=='D')//将第 k 个插入的数删除
        {
            scanf("%d",&k);
            remove(k+1);
        }
        else if(op[1]=='L')//在第 k 个插入的数左侧插入一个数
        {
            scanf("%d%d",&k,&x);
            insert(l[k+1],x);
        }
        else//在第 k 个插入的数右侧插入一个数
        {
            scanf("%d%d",&k,&x);
            insert(k+1,x);
        }
    }
    
    for(int i=r[0];i!=1;i=r[i]) printf("%d ",e[i]);
    
    
    return 0;
}