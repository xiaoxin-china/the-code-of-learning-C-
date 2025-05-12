#include<iostream>
using namespace std;

class base{};
class son:public base{};
class other{};

void text01()
{
    //C语言风格
    int a=10;
    double b = (double)a;
    printf("%lf\n",b);

    //C++风格   static_cast:基础类型之间，父类和子类的指针或者引用之即继承间（下行转换不安全，上行转换安全）
    //语法：static_cast<目标类型>(变量)
    
    //内置数据类型转换
    int c=10;
    double d = static_cast<double>(c);
    printf("%lf\n",d);

    //父子间转换    指针或引用
    //下行转换
    base * p1=new base();
    son * p2 = static_cast<son*>(p1);
    //上行转换
    son * p3 = new son();
    base *p4 = static_cast<base*>(p3);

    //非继承关系不行
    other * p5=new other();
    //son * p6 = static_cast<son*>(p5);  //编译错误,不是继承关系，转换无效
}
int main()
{
    text01();
    return 0;
}