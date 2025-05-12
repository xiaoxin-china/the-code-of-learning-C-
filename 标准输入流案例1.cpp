#include<iostream>
using namespace std;


//要求根据输入的内容是数字还是字符串（不含数字）来做输出

void text01()
{
string str;

cout<<"请输入一个数字或者字符串"<<endl;
char ch=cin.peek();//或者用cin.get(ch)与cin.ptuback()配合使用
if(ch>='0'&&ch<='9')
{
    int num;
    cin>>num;
    cout<<"您输入的是数字："<<num<<endl;
}
else
{
    cin>>str;
    cout<<"您输入的是字符串："<<str<<endl;
}
}
int main()
{
    text01();
    return 0;
}