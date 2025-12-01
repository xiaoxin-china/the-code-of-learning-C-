#include<iostream>
#include<queue>
#include<cstring>//用于memset
using namespace std;

int n,m,x,y;
int dis[450][450];//步数
//马的八个走法
int dx[8] = {-2,-1,1,2,-2,-1,1,2};
int dy[8] = {-1,-2,-2,-1,1,2,2,1};

int main()
{
    cin>>n>>m>>x>>y;
    memset(dis,-1,sizeof(dis));//初始化将所有点标记为-1，暂时不可到的点
    queue<pair<int,int>> q;
    dis[x][y]=0;//起点自己是0步
    q.push({x,y});
    while(!q.empty())
    {
        pair<int,int> t = q.front();//auto是c++11引入的自动推断数据类型的关键字，根据右边的值自己推断
        //auto t = q.front();//取队列第一个点
        q.pop();
        int cx = t.first;
        int cy = t.second;

        //扩展8个方向
        for(int i=0;i<8;i++)
        {
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&dis[nx][ny]==-1)
            {
                dis[nx][ny] = dis[cx][cy] + 1;
                q.push({nx,ny});
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j =1;j<=m;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}