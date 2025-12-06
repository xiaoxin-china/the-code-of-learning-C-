#include<iostream>
using namespace std;
int fa[1009];
int find_root(int a)
{
    if(fa[a]==a)return a;
    return fa[a] = find_root(fa[a]);
}
void unite(int a,int b)
{
    int ra = find_root(a);
    int rb = find_root(b);
    if(ra!=rb)fa[ra] = rb;
}
int main()
{
    while(true)
    {
        int n,m;
        cin>>n;
        if(n==0) return 0;
        for(int i=1;i<=n;i++)fa[i] = i;
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            int a,b;
            cin>>a>>b;
            unite(a,b);
        }
        int k=0;
        for(int i=1;i<=n;i++)
        {
            if(find_root(i)==i)k++;//有几个老大，就有几个连痛快
        }
        cout<<k-1<<endl;
    }

    return 0;
}