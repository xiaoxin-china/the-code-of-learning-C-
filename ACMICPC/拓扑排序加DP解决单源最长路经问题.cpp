#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
#define INF -4e18
int main()
{
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>> g(n+1);
    vector<ll>index(n+1,0);
    for(int i=1;i<=m;i++)
    {
        ll nn,mm,w;
        cin>>nn>>mm>>w;
        g[nn].push_back({mm,w});
        index[mm]++;
    }
    vector<ll> dp(n+1,INF);
    queue<ll> q;

    dp[1] = 0;
    for(ll i =1;i<=n;i++)
    {
        if(index[i]==0)
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        auto a = q.front();
        q.pop();
        for(auto b : g[a])
        {
            ll v = b.first;
            ll w = b.second;

            if(dp[a]!=INF)
            {
                dp[v] = max(dp[v],dp[a]+w);
            }
            index[v]--;
            if(index[v] == 0)
            {
                q.push(v);
            }
        }
    }

    if(dp[n]==INF)
    cout<<-1<<endl;
    else cout<<dp[n]<<endl;


    return 0;
}