#include<iostream>
#include<deque>
using namespace std;
//大小的操作：
//deque.size(); //返回容器中元素的个数
//deque.empty(); //判断容器是否为空
//deque.resize(int num); //重新指定容器的大小,若容器变长，则以默认值填充，若变短，则超出部分删除
//deque.resize(int num,elem)//重新指定容器的大小,若容器变长，则以elem填充，若变短，则超出部分删除

//deque中没有容量的概念
void printDeque(const deque<int>& d) {
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {
	deque<int> d1;
    if(d1.empty())
    {
        cout << "d1为空" << endl;
    }
    else
    {
        cout << "d1不为空,大小为：" << d1.size()<<endl;
    }
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);

    if(d1.empty())
    {
        cout << "d1为空" << endl;
    }
    else
    {
        cout << "d1不为空,大小为：" << d1.size()<<endl;
    }



    d1.resize(10);
    printDeque(d1);

    d1.resize(20,100);
    printDeque(d1);
}
int main() {
    test01();
	return 0;
}