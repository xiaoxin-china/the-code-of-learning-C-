#include<iostream>
#include<cmath>
using namespace std;
struct node
{
    int left;
    int right;
}tree[1000009];

int dfs(int u)
{
    if(u==0)
    return 0;

    int depth_l = dfs(tree[u].left);
    int depth_r = dfs(tree[u].right);
    return max(depth_l,depth_r)+1;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>tree[i].left>>tree[i].right;
    }
    int depth_max = dfs(1);
    cout<<depth_max<<endl;
    return 0;
}