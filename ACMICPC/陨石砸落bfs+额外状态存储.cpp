#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
const int MAXD = 1000000000;
int m;
int dis[305][305];
int fire[305][305];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int main()
{
    cin>>m;
    for(int i = 0;i<305;i++)//将fire每个值都设置成极大数，不能用memset，memset只能用于0和-1.
    {
        for(int j = 0;j<305;j++)
        {
            fire[i][j] = 1000000000;
        }
    }
    for(int i=1;i<=m;i++)
    {
        int x,y,t;
        cin>>x>>y>>t;
        int fx[5] = {x,x+1,x-1,x,x};
        int fy[5] = {y,y,y,y+1,y-1};
        for(int k=0;k<5;k++)
        {
            int nx = fx[k];
            int ny = fy[k];
            if(nx>=0&&nx<305&&ny>=0&&ny<305)
            {
                if(t<fire[nx][ny])
                fire[nx][ny] = min(fire[nx][ny],t);
            }
        } 
    }

    memset(dis,-1,sizeof(dis));
    if(fire[0][0]==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    dis[0][0] = 0;
    queue<pair<int , int>> q;
    q.push({0,0});
    while(!q.empty())
    {
        auto t = q.front();
        q.pop();
        int x = t.first;
        int y = t.second;
        int ans = dis[x][y];
        if(fire[x][y]==MAXD)
        {
            cout << ans << endl;
            return 0;
        } 
        for(int k = 0;k<4;k++)
        {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if(nx<0||ny<0||nx>=305||ny>=305)
            continue;
            if(dis[nx][ny]!=-1)continue;
            if(fire[nx][ny]>ans+1)
            {
                dis[nx][ny] = dis[x][y]+1;
                q.push({nx,ny});
            }
        }

    }

    cout<<-1<<endl;
    return 0;
}