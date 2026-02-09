#include<iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll qzh[100009];
    ll g[100009];
    ll n;
    g[0] = 0;
    qzh[0] = 0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>g[i];
    }
    qzh[1] = g[1];
    for(int i=2;i<=n;i++)
    {
        qzh[i] = qzh[i-1]+g[i];
        //cout<<qzh[i]<<" ";
    }

    ll m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        ll l,r;
        cin>>l>>r;
        cout<<qzh[r]-qzh[l-1]<<endl;
    }
    

    return 0;
}