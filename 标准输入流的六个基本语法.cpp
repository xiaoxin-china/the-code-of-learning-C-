#include<iostream>
using namespace std;
//输入输出流的基类是 ios
//文件的输入输出流对应的类是 fstream

void text01()
{
    //cin.get()  : 从缓冲区读取一个字符
    string ch;
    ch=cin.get();
    cout << "ch="<<ch << endl;

    ch=cin.get();
    cout << "ch="<<ch << endl;

    ch=cin.get();
    cout << "ch="<<ch << endl;

    ch=cin.get();
    cout << "ch="<<ch << endl;

    //输入“as”，第一次：a，第二次：s，第三次：\n，第四次：等待从键盘上输入
}

void text02()
{
    //cin.get(一个参数): 从缓冲区读取一个字符
    //cin.get(两个参数): 从缓冲区读取字符串

    char buf[1024];
    cin.get(buf,1024);//第一个参数是目标，第二个参数是最大的长度是多大
    //写入“hello world\n"，buf中存储的是“hello world”
    //换行符遗留在缓冲区中
    cout << "buf=" << buf << endl;
    char ch=cin.get();//检查缓冲区有无\n
    if(ch=='\n')
    {
        cout << "缓冲区有换行符" << endl;
    }
}

void text03()
{
    // cin.getline()    从缓冲区读取字符串
    //换行符不会遗留在缓冲区，而是直接扔掉，也输出换行符  
    char buf[1024];
    cin.getline(buf,1024);
    cout << "buf=" << buf << endl;
    char ch=cin.get();//检查缓冲区有无\n
    if(ch=='\n')
    {
        cout << "缓冲区有换行符" << endl;
    }
}

void text04()
{
    //cin.ignore()    忽略缓冲区中的一个字符
    //cin.ignore(int x);   忽略缓冲区中的x个字符

    cin.ignore();
    char ch=cin.get();
    cout << "ch=" << ch << endl;
}

void text05()
{
    //cin.peek()    查看缓冲区中的第一个字符，但不取走
    char ch=cin.peek();
    cout << "ch=" << ch << endl;
    ch=cin.get();
    cout << "ch=" << ch << endl;
}

void text06()
{
    //cin.putback()    将一个字符放回缓冲区
    char ch=cin.get();
    cin.putback(ch);//将ch放回原位置
    cout << "ch=" << ch << endl;
}
int main()
{
    text05();
    return 0;
}