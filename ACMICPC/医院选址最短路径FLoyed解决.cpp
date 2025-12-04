#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int INF = 1e9;


int main()
{
    int n;
    cin>>n;
    vector<int> w(n+1);
    vector<vector<int>> dist(n+1,vector<int>(n+1,INF));

    for(int i=1;i<=n;i++)
    {
        dist[i][i] = 0;
    }
    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin>>w[i]>>u>>v;
        if(u!=0)
        {
            dist[i][u] = 1;
            dist[u][i] = 1;
        }
        if(v!=0)
        {
            dist[i][v] = 1;
            dist[v][i] = 1;         
        }
    }

    for(int k = 1;k<=n;k++)//Floyed算法求点到点的最短路径
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][k]<INF&&dist[k][j]<INF)//确保从i到k，k到j可达，即可构建新的i到j路径
                {
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    long long ans = 1e9+7;
    for(int i = 1;i<=n;i++)
    {
        long long sum = 0;
        for(int j = 1;j<=n;j++)
        {
            sum+=w[j]*dist[i][j];
        }
        ans = sum<ans?sum:ans;
    }
    cout<<ans;





    return 0;
}