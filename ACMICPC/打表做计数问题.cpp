#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;
ll ans[100005];
int main()
{
    ll l ;
    cin>>l;
    if(l<2)
    {
    cout<<0;
    return 0;
    }
    //埃氏筛打素数表
    int n = (int)l;
    vector<bool> isprime(n+1,true);
    isprime[0]=false;
    isprime[1]=false;

    for(int i=2;i*i<=n;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=n;j+=i)//从i*i开始，因为从1到i的更小的因子已经处理过了。只需要每次往后处理（j+i）*i就行
            {//不考虑这微不足道的性能可以从i*2开始
                isprime[j] = false;
            }
        }
    }
    ll sum=0;
    ll count =0;
    for(ll i =2;i<=l;i++)
    {
        
        if(isprime[i])
        {
            if(sum+i<=l)
            {
                cout<<i<<endl;
                sum+=i;
                count++;
            }
            else{
                cout<<count<<endl;
                break;
            }
        }
        
    }
    return 0;
}