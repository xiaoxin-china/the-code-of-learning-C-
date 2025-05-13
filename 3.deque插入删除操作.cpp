#include<iostream>
#include<deque>
using namespace std;
//插入：
//push_back()   尾插
//push_front()  首插
//insert(const_iterator pos, elem)  向迭代器位置插入elem元素的数据
//insert(const_iterator pos, int count, elem)  向迭代器位置插入count个elem元素的数据
//insert(const_iterator pos, input_iterator first, input_iterator last)  向迭代器位置插入[first,last)区间的元素


//删除：
// pop_back()  尾删
// pop_front()  首删
// erase(const_iterator pos)  删除迭代器位置的数据
// erase(const_iterator first, const_iterator last)  删除[first,last)区间的元素
// clear()  清空容器

void printDeque(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    printDeque(d);

    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    printDeque(d);

    d.insert(d.begin()+1, 1000);
    printDeque(d);

    d.erase(d.begin());
    printDeque(d);
    d.erase(d.begin(), d.end()-1);
    printDeque(d);
    d.clear();
    printDeque(d);
}

int main()
{
    test01();
    return 0;
}