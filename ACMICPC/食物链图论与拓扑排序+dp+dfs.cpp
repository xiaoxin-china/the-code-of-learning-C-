#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MOD 80112002
typedef long long ll;


ll n , m;

int main()
{
    cin>>n>>m;
    vector<vector<int>> g(n+1);
    vector<int> indeg(n+1,0);
    vector<int> outdeg(n+1,0);

    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        indeg[v]++;
        outdeg[u]++;
    }
    vector<int> f(n+1,0);
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
            f[i] = 1;
        }
    }

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : g[u])
        {
            f[v] = (f[v]+f[u])%MOD;
            indeg[v]--;
            if(indeg[v]==0)
            {
                q.push(v);
            }
        }
    }


    ll ans = 0;
    for(int i=1;i<=n;i++)
    {
        if(outdeg[i]==0)
        {
            ans = (ans+f[i])%MOD;
        }
    }
    cout<<ans<<endl;


    return 0;
}
