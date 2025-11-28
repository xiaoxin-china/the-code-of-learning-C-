#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
    int a[3];
    for(int i=0;i<3;i++)
    {
        cin>>a[i];
    }
    sort(a,a+3);
    char c[3];
    map<char,int>mp;
    mp['A'] = a[0];
    mp['B'] = a[1];
    mp['C'] = a[2];
    for(int i=0;i<3;i++)
    {
        cin>>c[i];
        cout<<mp[c[i]]<<" ";
    }
    
    return 0;
}