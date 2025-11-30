#include<iostream>
using namespace std;
int ans;
int n,m;
char a[101][101];
void dfs(int x,int y)
{
    a[x][y] = '.';
    int dx,dy;
    for(int i=-1;i<=1;i++)
    {
        for(int j =-1;j<=1;j++)
        {
            dx=x+i;
            dy = y+j;
            if(dx>=1&&dx<=n&&dy>=1&&dy<=m&&a[dx][dy]=='W')
            {
                dfs(dx,dy);
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            if(a[i][j]=='W')
            {
                dfs(i,j);
                ans++;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}