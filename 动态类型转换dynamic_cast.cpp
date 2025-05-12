#include<iostream>
using namespace std;

//动态类型转换：dynamic_cast  ，是一种安全的数据类型转换，但是不允许内置数据类型进行类型转换，防止数据精度丢失或者截断
//语法：dynamic_cast<目标类型>(指针或者引用)    与static_cast语法相同

class base{};
class son:public base{};

void text01()
{

    //内置数据类型不能用
    int a=10;
    //double b=dynamic_cast<double>(a); //错误

    //父子类之间的转换可以用且仅仅是上行转换可用
    base* p1=new son();
   // son* p2 = dynamic_cast<son*>(p1); //不安全，下行转换

    son* p3 = new son();
    base *p4=dynamic_cast<base*>(p3);//安全，上行转换
}
int main()
{
    text01();
    return 0;
}