#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int a[100],b[100],c[100],d[100];
//a行，b列，c从左下到右上的对角线，d左上到右下的对角线
int total;
//解的总数
int n;
//输入的数

void print()
{
    if(total<=2)
    {
        for(int k=1;k<=n;k++)
        {
            cout<<a[k]<<" ";
        }
        cout<<endl;
    }
    total++;
}
void queen(int i)
{
    if(i>n)
    {
        print();
        return;
    }
    for(int j=1;j<=n;j++)
    {
        if((!b[j])&&(!c[i+j])&&(!d[i+n-j]))
        {
            a[i]=j;
            b[j] = 1;
            c[i+j] = 1;
            d[i+n-j] = 1;

            queen(i+1);

            b[j] = 0;
            c[i+j] = 0;
            d[i+n-j] = 0;
        }
    }
}
int main()
{
    cin>>n;
    queen(1);
    cout<<total<<endl;
    return 0;
}