#include<iostream>
using namespace std;

void func()throw(int)
{
    throw 1;
}
void text01()
{
    try
    {
        func();
    }
    catch(int)
    {
        //catch(int,double)   意味着只能接受int 与double类型
        //catch()   意味着不能接收任何类型
        cout<<"int异常"<<endl;
    }
}

int main()
{
    text01();
    return 0;
}