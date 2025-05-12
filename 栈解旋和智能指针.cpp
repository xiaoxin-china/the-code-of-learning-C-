
//栈解旋是一种机制，在处理异常时，从try开始，直到throw一抛出，throw前面的就会被依次销毁，而且顺序是和构造的顺序相反，防止一直占用内存，这就是栈解旋
#include<iostream>
using namespace std;

class person
{
    public:
    person()
    {
        cout<<"person 构造"<<endl;
    }

    ~person()
    {
        cout<<"person 析构"<<endl;
    }

};

void func()
{
    person p1;
    person p2;//栈解旋，throw前面的try的内容会被释放
                //但是有新问题，在堆上创建的释放不了怎么办，会造成内存泄漏
    person* p4=new person;    //堆上的不会释放
    unique_ptr<person> p3(new person());//智能指针，当函数结束时，自动释放内存
    throw 1;
}
int main()
{
    try
    {
        func();
    }
    catch(int)
    {
        cout<<"捕获int异常"<<endl;
    }
    
    return 0;
}