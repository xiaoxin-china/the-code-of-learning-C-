#include<iostream>
#include<vector>
using namespace std;


//注意：
//首先迭代器需要换个名字，因为要执行++操作，但是要让迭代器往头走，所以用  reverse_iterator
//其次，rbegin()返回的是最后一个元素的迭代器，rend()返回的是第一个元素的前一个位置
//其他与正向遍历一样
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    // 逆序遍历
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}