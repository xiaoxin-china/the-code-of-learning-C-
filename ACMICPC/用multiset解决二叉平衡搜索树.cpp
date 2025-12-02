#include<iostream>
#include<set>
using namespace std;
/*
#multiset用法：里面的元素按顺序排列，默认升序。不去重（这点和set是不同的）。

multiset<int>q;
//定义一个multiset，尖括号里写类型
//如果是自定义类型，需要重载小于号 

q.insert(x);
//插入一个数 x 

q.clear();
//清空 

q.erase(x);
//删除容器中的所有值为 x 的数 

q.erase(it);
//删除容器中迭代器it指向的元素 

q.empty();
//返回bool值，如果容器为空返回true，否则返回false 

q.size()
//返回元素个数

q.begin();
//返回首个元素的迭代器 

q.end();
//返回最后一个元素的下一个位置的迭代器 

q.count(x);
//返回容器中 x 的个数 

q.find(x);
//返回容器中第一个x的位置（迭代器），如果没有就返回q.end() 

q.lower_bound(x);
//返回容器中第一个大于等于x的数的迭代器 

q.upper_bound(x);
//返回容器中第一个大于x的数的迭代器 

*/
int main()
{
    multiset<int> q;
    q.insert(-2147483647);
    q.insert(2147483647);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int opt,a;
        cin>>opt>>a;
        if(opt==1)
        {
            int count=0;
            auto t = q.lower_bound(a);//第一个大于等于a的
            for(auto i=q.begin();i!=t;i++,count++);
            cout<<count<<endl;
        }
        else if(opt == 2)
        {
            auto t =q.begin();
            for(int cnt = 0;cnt<a;cnt++)
            ++t;
            cout<<*t<<endl;
            
        }
        else if(opt == 3)
        {
            auto it =q.lower_bound(a);
            it--;
            cout<<*it<<endl;
        }
        else if(opt==4)
        {
            cout<<*q.upper_bound(a)<<endl;
        }
        else if(opt == 5)
        {
            q.insert(a);
        }
    }




    return 0;
}