#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
struct node{
    int left;
    int right;
    int now_people;

}tree[109];
vector<long long> g[109];//建立邻接表将树转化为无向图
int main()
{
    int n;
    cin>>n;
    long long  ans = 1e9+7; 
    for(int i=1;i<=n;i++)
    {
        int w,u,v;
        cin>>w>>u>>v;
        tree[i].now_people = w;
        tree[i].left = u;
        tree[i].right = v;
        if(u!=0)
        {
            g[i].push_back(u);
            g[u].push_back(i);
        }
        if(v!=0)
        {
            g[i].push_back(v);
            g[v].push_back(i);
        }
    }

    int dist[109];
    for(int start = 1;start<=n;start++)
    {
        memset(dist,-1,sizeof(dist));
        queue<int> q;
        dist[start] = 0;
        q.push(start);
        while(!q.empty())//用bfs求dist距离：从start开始到每个位置的路径和
        {
            int x = q.front();
            q.pop();
            for(int y : g[x])//因为g是邻接表，这样遍历所有的x位置的该表这一行
            {
                if(dist[y]==-1)
                {
                    dist[y] = dist[x]+1;
                    q.push(y);
                }
            }
        }
        long long sum =0;
        for(int i=1;i<=n;i++)
        {
            sum += 1LL*tree[i].now_people * dist[i];
        }

        if(sum<ans)ans = sum;
    }



    
    cout<<ans;

    return 0;
}