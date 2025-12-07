#include<iostream>
#include<map>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<string,int> mp;
    long long ans = 0;
    while(n--)
    {
        string a,b;
        cin>>a>>b;
        string temp = a.substr(0,2);
        string self = temp+b;
        string need = b+temp;
        ans+=mp[need];
        mp[self]++;
    }
    cout<<ans<<endl;
    return 0;
}