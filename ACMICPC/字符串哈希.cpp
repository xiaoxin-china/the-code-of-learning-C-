#include<iostream>
#include<unordered_set>
using namespace std;

int main()
{
    int n;
    cin>>n;
    unordered_set<unsigned long long > st;//必须用
    const unsigned long long base1 = 131;
    const unsigned long long base2 = 1331;
    st.reserve(n*2);
    while(n--)
    {
        string s;
        cin>>s;
        unsigned long long h1 = 0,h2=0;
        for(unsigned c : s)
        {
            h1 = h1 * base1 + c;
            h2 = h2 * base2 + c;
        }
        unsigned long long key = h1 ^ h2*123123457693ULL;//双哈希揉成一个
        st.insert(key);//上面的大常熟后面的ULL：unsigned long long
        //不用担心溢出，溢出后会自己对2^64取余，属于自然溢出，保留2^64这么大的数
    }
    cout<<st.size()<<endl;


    return 0;
}