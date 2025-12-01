#include<iostream>
using namespace std;
int n;
int a[35][35];
void dfs(int x,int y)
{
    a[x][y]=-1;
    int dx[4] = {-1,1,0,0};//四联通
    int dy[4] = {0,0,-1,1};
    for(int k=0;k<4;k++)
    {
        int nx = x+dx[k];
        int ny = y+dy[k];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&a[nx][ny]==0)
        {
            dfs(nx,ny);
        }
    }
}
int main()
{
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    //从边界每个为0的点开始搜
    for(int j=1;j<=n;j++)
    {
        if(a[1][j]==0)dfs(1,j);
        if(a[n][j]==0)dfs(n,j);
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i][1]==0)dfs(i,1);
        if(a[i][n]==0)dfs(i,n);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==-1)
            cout<<0<<" ";
            else if(a[i][j]==0)
            cout<<2<<" ";
            else
            cout<<1<<' ';
        }
        cout<<endl;
    }

    return 0;
}