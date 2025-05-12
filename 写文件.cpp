#include<iostream>
using namespace std;
#include<fstream>//文件输入输出流所属的类
////只读：ios：：in
//// 只写：ios：：out 先清空再写
//// 追加写：ios：：app
//打开一个已有文件，将文件光标移至末尾：ios：：ate
////打开一个文件，如果存在就全清空全部数据，不存在就建立一个新文件：ios：：trunc
//以二进制的形式打开：ios：：binary
//以文本的形式打开：ios：：text
//打开已有文件，不会创立新文件，没有就打开失败 ios::nocreate
//如果文件不存在就创立新文件，存在就操作失败  ios::noreplace

//下面是组合型：
////ios::in|ios::out  以输入输出形式打开文件
////ios::in|ios::binary  以二进制输入形式打开文件
////ios::out|ios::binary  以二进制输出形式打开文件



//写文件，

    //通过write()函数写入文件
    //ofs.write((const char*) &p1,sizeof(p1));
class person
{
    public:
    string name;
    int age;
    person(string name,int age):name(name),age(age){}

};

void text01()
{
    person p1("tom",18);
    //创建输出流文件对象，头文件<fstream>

    ofstream ofs;
    //打开文件
    ofs.open("./text01.txt",ios::out|ios::trunc);
    if(!ofs.is_open())//判断文件是否打开成功的函数，成功返回1，失败返回0
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
    //写文件
    ofs.write((const char*) &p1,sizeof(p1));

    //关闭文件
    ofs.close();


}

//  通过流插入运算符<<写入文件
void text02()
{
    ofstream ofs;
    ofs.open("./text02.txt",ios::out|ios::trunc);

    if(!ofs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }

    ofs<<"姓名：tom"<<endl;
    ofs<<"年龄：18"<<endl;
    ofs<<"性别：男"<<endl;
    ofs.close();
}
int main()
{

    text01();
    text02();
    return 0;
}