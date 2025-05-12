#include<iostream>
using namespace std;
void text01()
{
    cout<<"请输入一个整数："<<endl;
    int num=0;
    while(1)
    {
        cin>>num;
        if(num<=10&&num>=1)
        {
            cout<<"输入的整数是："<<num<<endl;
            break;
        }
            //查看标识位置，0为正常，1为错误
            // cin.fail();

            //清除标识位必须要有
            cin.clear();    // 清除错误标志,恢复标识位
            string str;
            getline(cin,str);

            //下面是C语言的语法
            // char str[1024];
            // cin.getline(str,1024);
            cout<<"输入错误，请重新输入："<<endl;
        
    }
    
}
int main()
{
    text01();
    return 0;
}