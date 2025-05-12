#include<iostream>
#include<vector>
using namespace std;


void text01()
{
    vector<vector<int>> v;
    // 在创建三个小的容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    
    // 给每个小的容器添加数据
    for(int i=0; i<5; i++) // 假设每个小容器添加5个数据
    {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
    }

    //注意：：这里有坑，push_back()是指传递，如果先把v1，v2，v3添加到v中，那么v1，v2，v3再尾插数据，v里面不会发生变化，因为v里面存的是v1，v2，v3的副本，而不是v1，v2，v3本身
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    // 遍历大的容器

    for(vector<vector<int>>::iterator it=v.begin();it!=v.end();it++)
    {
        for(vector<int>::iterator vit=(*it).begin();vit!=(*it).end();vit++)
        {
            cout<<*vit<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    text01();
    cout<<1<<endl;
    return 0;
}