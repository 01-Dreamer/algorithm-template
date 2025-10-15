#include<iostream>

using namespace std;
int n;

void divide(int x)
{
    for(int i=2;i<=x/i;i++)
       if(x%i==0)
       {
           int s=0;
           while(x%i==0) x/=i,s++;
           cout<<i<<" "<<s<<endl;
       }
    if(x>1) cout<<x<<" "<<1<<endl;   
}


int main()
{
    cin>>n;
    
    int x;
    while(n--)
    {
        cin>>x;
        divide(x);
        cout<<endl;
    }
    
    
    return 0;
}