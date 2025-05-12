#include<iostream>
using namespace std;
void text01()
{
    cout.put('a');//像屏幕上输出一个字符
    char buf[20] ="hello world";
    cout.write(buf,2);//像屏幕上输出字符串buf的前2个字符,适用于c语言语法

    cout.put('a').put('b');
    char buf1[20] ="hello world";
    cout.write(buf1,strlen(buf1));//像屏幕上输出字符串buf的所有字符

    cout<<"hello world"<<endl;//最常用


    //格式化输出：
    // ....未完待续，后面用到在学
}

int main()
{
    text01();
    return 0;
}