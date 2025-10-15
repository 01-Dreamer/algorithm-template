#include<iostream>

using namespace std;

const int N=100010;
int b[N];


int main()
{
    int n=0,q=0,t=0;
    cin>>n>>q;
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    while(q--)
    {
        cin>>t;
        int l=0,r=n-1;
        while(l<r)
        {
            int mid=l+r>>1;
            if(b[mid]>=t) r=mid;
            else l=mid+1;
        }
        if(b[l]!=t) cout<<"-1 -1"<<endl;
        else
        {
            cout<<l<<" ";
            l=0,r=n-1;
            while(l<r)
            {
                int mid=l+r+1>>1;
                if(b[mid]<=t) l=mid;
                else r=mid-1;
            }
            cout<<l<<endl;
        }
    }


    return 0;
}