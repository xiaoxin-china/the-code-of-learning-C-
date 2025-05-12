#include<iostream>
using namespace std;
//语法与static_cast相同
//常量指针转为非常量指针，常量引用转为非常量引用
//或者是将非常量指针转为常量指针，非常量引用转为常量引用

//只能对指针或者引用使用，不能对普通变量使用
void text01()
{
    //对指针转换
    int *p=NULL;
    //将p转为常量指针const int *
    const int *p1=const_cast<const int *>(p);
    //将p1转为非常量指针int *
    int *p2=const_cast<int *>(p1);

    //对引用转换
    int num=10;
    int& ref=num;
    //将ref转为常量引用const int &
    const int& ref1=const_cast<const int&>(ref);
    //将ref1转为非常量引用int &
    int& ref2=const_cast<int&>(ref1);

    //不能对普通变量使用
    // int num1=10;  
    // const int num2=const_cast<const int>(num1);
    //const_cast只能用于指针和引用
}
int main()
{
    text01();
    return 0;
}