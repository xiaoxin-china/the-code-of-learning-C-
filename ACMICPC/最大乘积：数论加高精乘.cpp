#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans;

void fac(long long fact,vector<int>& an,vector<int>& ans)
{
    ans.clear();
    //reverse(an.begin(),an.end());
    long long lenan = an.size();
    ans.push_back(1);
    for(int i=0;i<lenan;i++)
    {
        int b = an[i];
        int carry =0;
  

        for(int k = 0;k<ans.size();k++)
        {
            int w = b*ans[k]+carry;
            ans[k] = w%10;
            carry = w/10;
        }
        while(carry>0)
        {
            ans.push_back(carry%10);
            carry/=10;
        }
    }
    reverse(ans.begin(),ans.end());
}


int main()
{
    int n;
    cin>>n;
    if(n==3)
    {
        cout<<3<<endl<<3<<endl;
        return 0;
    }
    if(n==4)
    {
        cout<<4<<endl<<4<<endl;
        return 0;
    }
    int sum = 0;
    for(int i=2;sum<=n;i++)
    {
        sum+=i;
        ans.push_back(i);
        if(sum>=n)
        break;
    }
    if(sum==n)
    {
        vector<int> bigs;
        long long fact=1;        
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
            //fact*=ans[i];
        }
        cout<<endl;
        fac(fact,ans,bigs);
        for(int i=0;i<bigs.size();i++)
        {
            cout<<bigs[i];
        }
        //cout<<fact<<endl;
    }
    else if(sum==n+1)
    {
        vector<int> bigs;
        vector<int> an;


        long long fact=1;       
        ans[ans.size()-1]+=1;
        for(int i=1;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
            an.push_back(ans[i]);
        }
        cout<<endl;
        fac(fact,an,bigs);
        for(int i=0;i<bigs.size();i++)
        {
            cout<<bigs[i];
        }
    }
    else
    {
        long long fact=1;
        vector<int> bigs;   
        vector<int> an;     
        for(int i=0;i<ans.size();i++)
        {
            
            if(ans[i]==(sum-n))
                continue;
            else
            {
                cout<<ans[i]<<" ";
                an.push_back(ans[i]);
            }
        }
        cout<<endl;
        fac(fact,an,bigs);
        for(int i=0;i<bigs.size();i++)
        {
            cout<<bigs[i];
        }
    }
}