#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;
int main()
{
    string a[2509];
    int i=1;
    string s;
    while(1)
    {
        getline(cin,a[i]);
        s+=a[i];
        if(a[i].find('E')!=-1)
        {
            break;
        }
        i++;
    }
    int pos = s.find('E');
    long long count1 = 0;
    long long count2 = 0;

    for(int i=0;i<=pos;i++)
    {

        if(s[i] == 'W')
        count1++;
        else if(s[i]=='L')
        count2++;    
        else if(s[i]=='E')
        {
            cout<<count1<<":"<<count2<<endl;
            count1 = 0;
            count2 = 0;
            break;
        }
        
        long long maxs = count1>count2?count1:count2;
        if(maxs>=11&&(abs(count1-count2)>=2))
        {
            cout<<count1<<":"<<count2<<endl;
            count1 = 0;
            count2 = 0;
        }
        

    }
    cout<<endl;

    for(int i=0;i<=pos;i++)
    {

        if(s[i] == 'W')
        count1++;
        else if(s[i]=='L')
        count2++;    
        else if(s[i]=='E')
        {
            cout<<count1<<":"<<count2<<endl;
            count1 = 0;
            count2 = 0;
            break;
        }
        
        long long maxs = count1>count2?count1:count2;
        if(maxs>=21&&(abs(count1-count2)>=2))
        {
            cout<<count1<<":"<<count2<<endl;
            count1 = 0;
            count2 = 0;
        }
        

    }


    return 0;
}