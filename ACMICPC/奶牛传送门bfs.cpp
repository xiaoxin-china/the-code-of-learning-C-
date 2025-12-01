#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n,m;
const int MAXD = 305;
int dis[MAXD][MAXD];
char a[MAXD][MAXD];

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int cut[26];
pair<int ,int> z[26][2];

int main()
{
    cin>>n>>m;
    memset(dis,-1,sizeof(dis));
    memset(cut,0,sizeof(cut));
    queue<pair<int ,int>> q;
    int anx,any;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='@')
            {
                dis[i][j]=0;
                anx = i;
                any = j;
                q.push({i,j});
            }
            if(a[i][j]>='A'&&a[i][j]<='Z')
            {
                int id = a[i][j]-'A';
                z[id][cut[id]] = {i,j};
                cut[id]++;
            }
        }
    }
    while(!q.empty())
    {
        auto t = q.front();
        q.pop();
        int cx = t.first;
        int cy = t.second;
        int ct =dis[cx][cy];
        if(a[cx][cy]=='=')
        {
            cout<<dis[cx][cy]<<endl;
            return 0;
        }
        for(int k =0;k<4;k++)
        {
            int nx = cx+dx[k];
            int ny = cy+dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(a[nx][ny]=='#')continue;
            if(dis[nx][ny]==-1&&(a[nx][ny]=='.'||a[nx][ny]=='@'||a[nx][ny]=='='))
            {
                dis[nx][ny] = dis[cx][cy]+1;
                q.push({nx,ny});
            }
            else if((a[nx][ny]<='Z'&&a[nx][ny]>='A'))
            {
                int id = a[nx][ny]-'A';
                auto p1 = z[id][0];
                auto p2 = z[id][1];
                int tx = p1.first == nx? p2.first:p1.first;
                int ty = p1.second == ny? p2.second:p1.second;
                if(dis[tx][ty]==-1)
                {
                    dis[tx][ty] = dis[cx][cy]+1;
                    q.push({tx,ty});
                }
                
            }
        }

    }

    cout<<-1<<endl;
    return 0;
}