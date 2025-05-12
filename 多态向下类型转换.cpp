#include<iostream>
using namespace std;
class base
{
    public:

};

class son : public base
{
    public:

};
void text01()
{
    //向下类型转换      ::  不安全
    base *p = new son();
    son *p1 = (son*)p;  
    cout<<p1<<endl;
    //向上类型转换      ::  安全
    son *p2 = new son();
    base *p3 = p2;
    cout<<p3<<endl;
}
int main()
{
  text01();  
    return 0;
}