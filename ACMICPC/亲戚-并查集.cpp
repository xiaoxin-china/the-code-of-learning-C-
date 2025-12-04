#include<iostream>
using namespace std;
int fa[5005];
int find(int x)
{
    while(fa[x]!=x)//如果每个人的老大不是自己，那x就变成他自己的老大，持续找老大
    x = fa[x];
    return x;
}

void unite(int a,int b)
{
    int ra = find(a);
    int rb = find(b);
    if(ra!=rb)//如果a和b的老大不是一个人，将a挂在b下面，让a认b为老大
    {
        fa[ra] = rb;
    }
    
}
int main()
{
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        unite(x,y);
    }

    for(int i=1;i<=p;i++)
    {
        int a,b;
        cin>>a>>b;
        if(find(a)!=find(b))
        cout<<"No"<<endl;
        else
        cout<<"Yes"<<endl;
    }

    return 0;
}