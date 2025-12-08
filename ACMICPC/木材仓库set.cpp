#include<iostream>
#include<set>
#include<cmath>
using namespace std;
int main()
{
    int n;
    cin>>n;
    set<long long > s;

    while(n--)
    {
        long long opt,length;
        cin>>opt>>length;
        if(opt == 1)
        {
            if(s.find(length)==s.end())
            s.insert(length);
            else 
            {
                cout<<"Already Exist"<<endl;
            }
        }
        else
        {
            if(s.empty())
            {
                cout<<"Empty"<<endl;
                continue;
            }
            auto it = s.lower_bound(length);
            long long take;
            if(it != s.end() && *it == length)
            {
                cout<<length<<endl;
                s.erase(length);
            }
            else if(it!=s.end()&&it!=s.begin()&& *it!=length)
            {
                long long left = *prev(it);
                long long right = *it;
                if(llabs(left-length)<=llabs(right-length))
                {
                    cout<<left<<endl;
                    s.erase(left);
                }
                else{
                    cout<<right<<endl;
                    s.erase(right);
                }
            }
            else if(it==s.begin())
            {
                take = *s.lower_bound(length);
                cout<<take<<endl;
                s.erase(take);
            }
            else if(it == s.end())
            {
                take = *prev(s.end());
                cout<<take<<endl;
                s.erase(take);
            }

        }
    }

    return 0;
}