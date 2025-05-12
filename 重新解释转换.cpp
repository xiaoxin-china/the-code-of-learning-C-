#include<iostream>
using namespace std;
//这是一个非常底层的转换，它允许你将任何指针类型转换为任何其他指针类型，包括函数指针。
//这是一个非常危险的转换，因为它破坏了类型系统，可能导致未定义行为。
//不安全，因为太灵活
//语法：reinterpret_cast<other*>(p1)
class base{};
class other{};
int main()
{
    base* p1=NULL;
    other* p2=reinterpret_cast<other*>(p1);//
    return 0;
}