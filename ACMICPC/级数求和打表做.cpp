#include<iostream>
using namespace std;
const int MAXD = 30000000;
double ans[MAXD+5];
int main()
{
    double k;
    cin>>k;
    double t = 1.0;
    ans[1] = 1.0;
    int i=1;
    for(i=2;t <= 15;i++)
    {
        t+=1.0/i;
        ans[i] = t;
    }
    for(int j = 1;j<i;j++)
    {
        if(ans[j]>k)
        {
            cout<<j;
            break;
        }

    }
    return 0;
}