#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    string a,b;

    //getline(cin,a);
    //getline(cin,b);
    cin>>a>>b;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());

    int lena = a.length();
    int lenb = b.length();
    int len = lena+lenb;
    vector<int> sum(len,0);
    int carry = 0;
    
    for(int i = 0;i<lena;i++)
    {
        for(int j=0;j<lenb;j++)
        {
            //最后统一处理进位
            sum[i+j] += (b[j]-'0')*(a[i]-'0');//错位
        }
    }

    for(int i=0;i<len-1;i++)
    {
        if(sum[i]>=10)
        {
            //统一进位
            sum[i+1]+=sum[i]/10;
            sum[i]%=10;
        }
    }
    while(len>1&&sum[len-1]==0)
    {
        len--;
    }
    //reverse(sum.begin(),sum.end());
    for(int i=len-1;i>=0;i--)
    cout<<sum[i];

    return 0;
}