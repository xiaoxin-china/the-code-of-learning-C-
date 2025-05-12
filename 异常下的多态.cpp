#include<iostream>
using namespace std;


class baseexception
{
    public:
    virtual void prienterror()
    {

    }

};

class nullpointer : public baseexception
{
    public:
    void prienterror()
    {
        cout<<"空指针异常"<<endl;
    }
};

class outofrange : public baseexception
{
    public:
    void prienterror()
    {
        cout<<"数组越界异常"<<endl;
    }
};

void func()
{
    throw outofrange();
}
void text01()
{
    try
    {
        func();
    }
    catch(baseexception &e)//多态的使用，父类指针或者引用指向子类的对象（用其函数或者成员）
    {
        e.prienterror();
    }

}
int main()
{
    text01();
    return 0;
}