#include<iostream>
using namespace std;
#include<fstream>//头文件别忘了

class person
{
    public:
    string name;
    int age;

};

//读文件方式1：
//read方式读文件
void text01()
{
    ifstream ifs;
    ifs.open("./text01.txt",ios::in);
    if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
    person p;
    ifs.read((char *)&p,sizeof(person));
    cout<<"姓名："<<p.name<<endl<<"年龄："<<p.age<<endl;
    ifs.close();

}

//读文件方式2：
//>>方式读文件
void text02()
{
    ifstream ifs;
    ifs.open("./text02.txt",ios::in);
    if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }

    string buf;
    while(ifs>>buf)
    {
        cout<<buf<<endl;
    }
    ifs.close();
}


//读文件方式3：
//getline方式读文件
void text03()
{
    ifstream ifs;
    ifs.open("./text02.txt",ios::in);
    if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }

    string buf;
    while(getline(ifs,buf))
    {
        cout<<buf<<endl;
    }
    ifs.close();
}


//读文件方式4：
//get方式读文件
void text04()
{
    ifstream ifs;
    ifs.open("./text02.txt",ios::in);
    if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }

    char buf[1024];
    while(ifs.getline(buf,sizeof(buf)))
    {
        cout<<buf<<endl;
    }
    ifs.close();
}

//读文件方式5：
//while(c=ifs.get()!=EOF)方式读文件

void text05()
{

    ifstream ifs;
    ifs.open("./text02.txt",ios::in);
    if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
    char c;
    while((c=ifs.get())!=EOF)
    {
        cout<<c;
    }
    ifs.close();

}
int main()
{
    text05();
    return 0;
}