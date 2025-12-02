#include<iostream>
#include<queue>
using namespace std;
int L[1000009],R[1000009];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>L[i]>>R[i];
    }
    queue<pair<int,int>> q;
    q.push({1,1});
    int ans=0;
    while(!q.empty())
    {
        auto t = q.front();
        q.pop();
        int c = t.first;
        int cd = t.second;
        ans = max(ans,cd);
        if(L[c] != 0)q.push({L[c],cd+1});
        if(R[c] != 0)q.push({R[c],cd+1});
    }
    cout<<ans;
}