#include<iostream>
#include<vector>
using namespace std;


//at(int idx)  //返回指定位置元素的引用,更安全
//operator[]  //返回指定位置元素的引用,与at()功能相同，他俩的区别是，如果越界，at会返回out_of_range异常，而[]会直接让程序崩溃

//front()  //返回第一个元素的引用
//back()  //返回最后一个元素的引用


int main()
{

    vector<int> v1;
    for(int i = 0; i < 10; i++)
    {
        v1.push_back(i);

    }
    //除了用迭代器，也可以这样用【】操作遍历访问
    for(int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
    //除了用迭代器，也可以这样用v.at(i)操作遍历访问
    for(int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " ";
    }
    cout << endl;


    //输出第一个元素和最后一个元素
    cout << v1.front() << endl;
    cout << v1.back() << endl;

    try
    {
        cout<< v1.at(20) << endl;
    }
    catch(const exception& e)
    {
        cerr << e.what() << '\n';
    }
    return 0;   
}