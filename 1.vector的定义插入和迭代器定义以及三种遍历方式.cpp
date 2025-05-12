#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//头文件：#include<vector>

//容器：vector相当于动态数组
//算法：for_each
//迭代器：vector<类型>::iterator it;

//vector语法使用：vextor<类型名>名称        vector<int> v1;
//向容器尾部插入成员：v1.push_back(元素)     v1.push_back(1);

//通过迭代器遍历容器
//成员函数begin()返回容器中第一个元素的位置
//成员函数end()返回容器中最后一个元素的下一个元素的位置

void text01()
{
    //遍历第一种方式：
    vector<int> v1;

    //向容器中添加数据
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    //通过迭代器遍历容器
    vector<int>::iterator itbegin;//起始迭代器
    itbegin = v1.begin();

    vector<int>::iterator itend;//结束迭代器
    itend = v1.end();

    while(itbegin !=itend)
    {
        cout << *itbegin <<" ";
        itbegin++;
    }
    cout<<endl;

}


void text02()
{
    //遍历第二种方式：
    vector<int> v1;

    //向容器中添加数据
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    //通过迭代器遍历容器
    vector<int>::iterator it;
    for(it=v1.begin();it!=v1.end();it++)
    {
        cout << *it <<" ";
    }
    cout<<endl;
}



void myprint(int val)//val是容器中的元素，下面的函数是你要遍历这个容器然后做的事情
{
    cout << val << " ";
}
void text03()
{
    //遍历第三种方式：
    vector<int> v1;

    //向容器中添加数据
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    //通过迭代器遍历容器
    //for_each(v1.begin(),v1.end(),myprint);//myprint为函数,需要头文件#include<algorithm>
    for_each(v1.begin(),v1.end(),myprint);//myprint为函数
    cout<<endl;
}
int main()
{
    text01();
    text02();
    text03();
    return 0;
}