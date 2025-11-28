#include<iostream>
using namespace std;
int main()
{
    int sum;
    cin>>sum;
    int money[1000086];
    int max = 99999999;
    for(int i=1;i<=3;i++)
    {
        int n,m;
        cin>>n>>m;
        money[i]=((sum+n-1)/n)*m;//!!!!!!!sum/n向上取整
        if(money[i]<max)
        {
            max=money[i];
        }
    }
    cout<<max<<endl;


    return 0;
}