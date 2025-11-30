#include<iostream>
#include<string>
#include <algorithm>
using namespace std;

int main()
{
    string a,b;
    string sum;
    getline(cin,a);
    getline(cin,b);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    //cout<<"a:"<<a<<endl;
    //cout<<"b:"<<b<<endl;
    int carry = 0;
    int lena = a.length();
    int lenb = b.length();
    //cout<<"lena:"<<lena<<endl;
    ///cout<<"lenb:"<<lenb<<endl;
    int len = lena>lenb?lena:lenb;
    //cout<<"len:"<<len<<endl;
    for(int i=0;i<len;i++)
    {
        int x = carry;
        if(i<lena) x += a[i] - '0';
        if(i<lenb) x += b[i] - '0';
        //cout<<"x:"<<x<<endl;
        sum.push_back((x%10)+'0');
        //cout<<"sum["<<i<<"]:"<<sum[i]<<endl;
        //cout<<"carry:"<<carry<<endl;
        carry = x/10;
    }
    while(carry!=0)
    {
        int x = carry%10;
        sum.push_back(x + '0');
        carry/=10;
    }

    reverse(sum.begin(),sum.end());
    cout<<sum<<endl;

    return 0;
}