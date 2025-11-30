#include<iostream>
using namespace std;
int ans ;
int n;
int k;
int a[100];
bool isprime(int q)
{
    if(q==1)
    return false;
    for(int j = 2;j*j<q;j++)
    {
        if(q%j==0)
        return false;
    }
    return true;
}
void dfs(int now,int sum,int sid)
{
    //现在已经选了now个，当前总和为sum
    //sid是这次选数的下标，即我们从a[sid]开始选
    if(now == k)
    {
        if(isprime(sum))
        {
            ans++;
        }
        return;
    }

    for(int i = sid;i<=n-k+now+1;i++)
    {
        dfs(now+1,sum+a[i],i+1);
    }
    return;

}
int main()
{
    cin>>n>>k;
    for(int i =1;i<=n;i++)
    {
        int t;
        cin>>t;
        a[i] = t;
    }
    dfs(0,0,1);
    cout<<ans<<endl;

    return 0;
}