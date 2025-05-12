#include<iostream>
using namespace std;
// vector预留空间reserve
// reserve函数作用：提前设置vector容量大小，避免vector频繁的扩容操作,节省内存，节省时间
//语法：v.reserve(int n);
//注意：预留的空间在复制之前不可访问

//利用reverse可以节省内存，因为比如说要插入10万个数据，vector会自动扩容，内存会来到13
//所以我们先留出10万的内存空间，然后往里面插，这样在10万以内的话内存就不会自动扩容

void text01()
{
    vector<int> v;
    //预留空间
    v.reserve(100000);
    int num = 0;
    int i = 0;
    for(i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }
    cout << "size = " << v.size() << endl;
    cout << "capacity = " << v.capacity() << endl;
}

int main()
{
    text01();
    return 0;
}