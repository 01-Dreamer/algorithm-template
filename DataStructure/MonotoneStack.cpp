#include<iostream>

using namespace std;
const int N=1e5+10;
int stk[N],top;
int n;


int main()
{
    scanf("%d",&n);
    
    int x;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        while(top&&stk[top]>=x) top--;
        
        if(top) printf("%d ",stk[top]);
        else printf("-1 ");
        
        stk[++top]=x;
    }
    
    
    return 0;
}