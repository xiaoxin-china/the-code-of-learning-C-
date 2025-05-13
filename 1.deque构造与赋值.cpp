//与vector的区别，deque是双端数组，在头部进行插入与删除的效率比vector高，但是访问元素的速度比vector慢
#include <iostream>
#include <deque>
using namespace std;
//deque的本质不是连续的地址，而是一段一段的，通过其中的中控器连起来

//构造：
//deque<T> deqT  默认构造
//deque(beg, end)  构造函数将[beg, end)区间中的元素拷贝给本身
//deque(n, elem)   构造函数将n个elem拷贝给本身
//deque(const deque &deq)  拷贝构造

//赋值操作：
// deque &operator=(const deque &deq);  //重载等号操作符
//assign(beg, end)  将[beg, end)区间中的元素拷贝赋值给本身
//assign(n, elem)   将n个elem拷贝赋值给本身


void printdeque(const deque<int> &q)
{
    for(deque<int>::const_iterator it =q.begin();it!=q.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void text01()
{
    deque<int> deq1;
    deq1.push_back(1);
    deq1.push_back(2); 
    deq1.push_back(3);
    printdeque(deq1);


    deque<int> d2(deq1.begin(),deq1.end());
    printdeque(d2);

    deque<int> d3(10, 100);
    printdeque(d3);

    deque<int> d4(d3);
    printdeque(d4);
}

void text02()
{
    deque<int> d1;
    d1.push_back(1);
    d1.push_back(2); 
    d1.push_back(3);

    deque<int> d2;
    d2 = d1;
    printdeque(d2);

    deque<int> d3;
    d3.assign(d2.begin(),d2.end());
    printdeque(d3);

    deque<int> d4;
    d4.assign(10, 100);
    printdeque(d4);

    
}
int main()
{
    text02();
    return 0;
}