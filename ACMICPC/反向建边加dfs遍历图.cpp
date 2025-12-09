#include<iostream>
#include<vector>
using namespace std;
const int MAXL = 100009;
int N,M,A[MAXL];
vector<int> G[MAXL];//存图

void dfs(int x,int d)//d就是反向遍历的时候的该原点，也就是最大的这个点
{
    if(A[x])return;
    A[x] = d;
    for(int i = 0;i<G[x].size();i++)
    dfs(G[x][i],d);
}
int main()
{
    cin>>N>>M;
    for(int i=1;i<=M;i++)
    {
        int u,v;
        cin>>u>>v;
        G[v].push_back(u);//反向存图，遍历的时候代表正常图里的所有u都能到v
    }

    for(int i = N;i;i--)dfs(i,i);
    for(int i=1;i<=N;i++)
    cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}