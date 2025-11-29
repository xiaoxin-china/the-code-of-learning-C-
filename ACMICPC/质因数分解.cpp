#include<iostream>
using namespace std;
/*我的方法：找质数，在质数的前提下判断是否可以整除法，这个过程可以反转*/
/*新数论思维：唯一分解定理:任意一个大于1的整数都能唯一分解为若干质数的乘积，所以只需要找n%i==0即可
因为题目中说了n为两个不同质数的乘积
为什么不会被合数整除？
因为该数n的因子是两个质数，题目中已经说了，如果被合数整除，意味着他的因子至少有一个能被合数整除，与质数冲突
*/
bool isprime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    int max=0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(isprime(i))
            {
            max = i;
            if(n/i>max)
            max = n/i;
            }
        }
    }
    cout<<max;
    return 0;
}