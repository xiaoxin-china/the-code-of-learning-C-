#include<iostream>
using namespace std;
#include<stack>

//栈无遍历行为

//构造：
//stack<T> stk; //默认构造形式
//stack(const stack &stk); //拷贝构造函数

//赋值操作：
// push(elem);
// pop();
// top();

// 大小操作：
// empty();
// size();

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    stack<int> s2(s);

    stack<int> s3;
    s3 = s;

    cout << s.size() << endl;

    while (!s.empty())
    {
        cout << s.top() << endl;
        s.pop();
    }
    cout << s.size() << endl;
return 0;

}