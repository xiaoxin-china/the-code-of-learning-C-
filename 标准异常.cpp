#include<iostream>
using namespace std;
#include<stdexcept>

class person
{
    public:
    person(int age)
    {
        if(age<0)
        {
            throw out_of_range("年龄不能为负数");//其中一个子类
        }
        else
        {
            this->age=age;
        }
    }
    int age;
};

int main()
{
    try
    {
        person p1(-1);
        cout<<p1.age<<endl;
    }
    catch(exception &e) //exception是标准异常类的基类，所有标准异常类都继承自exception类
    {
        cout<<e.what()<<endl;//输出异常信息的方式：e.what()
    }
    return 0;
}