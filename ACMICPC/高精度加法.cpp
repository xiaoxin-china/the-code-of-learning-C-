#include<iostream>
#include<vector>

using namespace std;
const int MAXD = 200;
int main()
{
    int n;
    cin>>n;
    int sum[MAXD];
    int fact[MAXD];
    int lensum = 1;
    int lenfact = 1;
   
    fact[0] = 1;
    sum[0] = 0;

    for(int i=1;i<=n;i++)
    {
        if(i>1)
        {
        int carry = 0;
        for(int j=0;j<lenfact;j++)
        {
            int x = fact[j]*i+carry;
            fact[j] = x % 10;
            carry = x/10;
        }
        while(carry>0)
        {
            fact[lenfact]=carry%10;
            carry/=10;
            lenfact++;
        }
        }
        int carry = 0;
        int len = (lenfact>lensum?lenfact:lensum);
        for(int j=0;j<len;j++)
        {
            int x =carry;
            if(j<lensum)x+=sum[j];
            if(j<lenfact)x+=fact[j];
            sum[j] = x%10;
            carry = x/10;
        }
        if(carry>0)
        {
            sum[len] = carry;
            len++;
        }
        lensum = len;

    }
    for(int i = lensum -1;i>=0;--i)
    {
        cout<<sum[i];
    }
    return 0;
}