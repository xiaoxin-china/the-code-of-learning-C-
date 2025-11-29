#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
//范围最大为1亿，所以不管是打素数表还是回文数表都会栈溢出或者TLE，所以正常判断
//因为回文数的数据更少，所以放&&前面回过，否则过不了
bool panduan(int n)
{
    int original = n;
    int reversed = 0;
    while(n>0)
    {
        reversed = reversed*10+n%10;//判断回文数方法
        n/=10;
    }
    return original==reversed;
}
bool isprime(int n)
{
    for(int i = 2;i*i<=n;i++)
    {
        if(n%i==0)  //判断质数方法
        return false;
    }
    return true;
}
int main()
{
    int left,right;
    cin>>left>>right;
    for(int i=left;i<=right;i++)
    {
        if(panduan(i)&&isprime(i))
        cout<<i<<endl;
    }
    
    return 0;
}
