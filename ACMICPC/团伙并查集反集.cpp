#include<iostream>
#include<set>
using namespace std;
int fa[2005];
int find(int x)
{
    if(x==fa[x])
    return x;
    else 
    return fa[x] = find(fa[x]);
}

void unite(int a,int b)
{
    auto ca = find(a);
    auto cb = find(b);
    if(ca!=cb)
    {
        fa[ca] = cb;
    }
}
int main()
{
    int n;
    int m;
    cin>>n;
    cin>>m;
    for(int i=1;i<=2*n;i++)fa[i] = i;
    for(int i = 1;i<=m;i++)
    {
        char opt;
        int p,q;
        cin>>opt>>p>>q;
        if(opt == 'E')
        {
            unite(q+n,p);
            unite(p+n,q);
        }
        else
        {
            unite(q,p);
            //unite(q+n,p+n);//朋友的朋友
        }
    }
    int s = 0;
    for(int i=1;i<=n;i++){
        if(find(i) == i)s++;
    }
    cout<<s;//祖先数就是团伙数
    return 0;
}