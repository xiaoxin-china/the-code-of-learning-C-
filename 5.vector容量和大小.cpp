#include<iostream>
using namespace std;
#include<vector>

//empty()  判断容器是否为空
//size()  容器中元素个数
//capacity()  容器容量
//resize(int num)  重新指定容器大小,如果原先是{1,2,3,4,5},然后如果容器变短resize(3),那么容器中元素为{1,2,3}；如果容器变长，则以默认值填充
//resize(int num,int val)  重新指定容器大小,如果原先是{1,2,3,4,5},然后如果容器变短resize(3,10),那么容器中元素为{1,2,3}；如果容器变长，则以val填充预留空间
void text01()
{
    int arr[] = {1,2,3,4,5};
    vector<int> v;
    v.assign(arr,arr+sizeof(arr)/sizeof(int));

    if(v.empty())
    {
        cout<<"v is empty"<<endl;
    }
    else
    {
        cout<<"v is not empty"<<"  "<<v.capacity()<<"   "<<v.size()<<endl;
    }

    //手动扩容vector大小
    v.resize(10);
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<"  ";
    }
    cout<<endl;

    v.resize(12,10);
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<"  ";
    }
    cout<<endl;

    //看看容量变不变
    cout<<"v is not empty"<<"  "<<v.capacity()<<"   "<<v.size()<<endl;//按照曾经扩到最大的取


}

int main()
{
    text01();

    return 0;
}
