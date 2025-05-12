#include<iostream>
#include<vector>

using namespace std;

//vector里面的内容是存放在堆上的，vector本身直接定义的话是放在栈上，但是也可以通过new的形式放到堆上
//auto* vec = new vector<int>();  // vec对象本身在堆上，vec指向的vector对象在堆上
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

void test01()
{
    //存放自定义类型
    vector<Person> v;
    Person p1("Tom", 18);
    Person p2("Jerry", 20);
    //这里传入的是副本，用的拷贝构造
    //也就是p1 p2被释放后这个vector还可以用
    v.push_back(p1);
    v.push_back(p2);

    for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        // (*it)==(<vector的类型>)
        // (*it) 是person类型的对象，解引用之后就可以用点操作访问成员变量了 
        //或者不用接引用，直接用it这个指针访问成员变量->操作符
        cout << "Name: " << (*it).m_Name << " Age: " << it->m_Age << endl;//可以解引用然后用点操作或者是当作指针用箭头操作
    }
}

void test02()
{
    //存放自定义类型指针
    vector<Person*> v;
    Person p1("Tom", 18);
    Person p2("Jerry", 20);
    //这里传入的是地址，是把原文件放进去了
    //也就是p1 p2被释放后这个vector就用不了了
    v.push_back(&p1);
    v.push_back(&p2);

    for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
    {
        // (*it)是person*类型的指针，解引用之后就可以用箭头访问成员变量了
        cout << "Name: " << (*it)->m_Name << " Age: " << (*it)->m_Age << endl;
    }
}
int main()
{
    test01();
    test02();
    return 0;
}