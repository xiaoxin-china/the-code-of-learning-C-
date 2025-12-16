#include<iostream>
#include<queue>
#include<vector>
typedef long long ll;
using namespace std;    

const ll INF = 1e18;
int main()
{
    int n,m,s;
    cin>>n>>m>>s;

    vector<vector<pair<int , ll>>>graph(n+1);
    for(int i=0;i<m;i++)//存图
    {
        int u,v;
        ll w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }

    vector<ll> dist(n+1,INF);//dist[i]：s到i最短距离
    vector<bool> vis(n+1,false);

    //小根堆
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;

    dist[s] = 0;
    pq.push({0,s});

    while(!pq.empty())
    {
        auto [d,u] = pq.top();
        pq.pop();

        if(vis[u])
        continue;

        vis[u] = true;

        for(auto [v,w] : graph[u])
        {
            if(dist[u] + w < dist[v])//我先走到u再从u到v会不会比我之前的路更短
            {
                dist[v] = dist[u] + w;//会的话把这个新的更短的v重新扔进优先队列
                pq.push({dist[v],v});//这里vis用到了用法，下一次遍历到v时，一定是先遍历dist最短的v，然后讲vis设置为true，就不会再遍历比较长的v了
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<dist[i]<<' ';
    }
    return 0;
}