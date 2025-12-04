#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n,m,p;
    cin>>n>>m>>p;
    vector<vector<int>> g(n+1);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=p;i++)
    {
        int a,b;
        cin>>a>>b;
        vector<int> vis(n+1 , 0);
        queue<int> q;
        vis[a] = 1;
        q.push(a);

        bool ok = false;

        while(!q.empty())
        {
            int cur = q.front();
            q.pop();

            if(cur ==b)
            {
                ok = true;
                break;
            }
            for(int nxt : g[cur])
            {
                if(!vis[nxt])
                {
                    vis[nxt]=1;
                    q.push(nxt);
                }
            }
        }
        cout<<( ok ?"YES":"No")<<endl;
    }
    


    return 0;
}