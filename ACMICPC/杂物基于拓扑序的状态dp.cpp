#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

int n;
//转移方程
//dp[k] = max(dp[1],dp[2]...,dp[k-1])+len(k)

int main()
{
    cin>>n;
    vector<int> len(n+1);//每个任务的时间
    vector<int> dp(n+1);//每个任务的前置条件的所有时间
    int ans = 0;
    for(int i=1;i<=n;i++)
    {
        int id ;
        cin>>id;
        cin>>len[id];
        int pre;
        int mx = 0;
        while(true)
        {
            cin>>pre;
            if(pre==0)
            break;
            mx = max(mx,dp[pre]);
        }
        dp[id] = mx + len[id];
        ans = max(ans,dp[id]);
    }
    cout<<ans<<endl;


    return 0;
}