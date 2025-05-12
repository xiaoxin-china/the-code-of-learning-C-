#include<iostream>
using namespace std;


void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void text01()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int> v2;
    v2.push_back(100);
    v2.push_back(200);
    v2.push_back(300);

    v1.swap(v2);
    printVector(v1);

}

//巧用swap实现收缩内存
void text02()
{
    vector<int> v;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }
    cout << "v.capacity() = " << v.capacity() << endl;
    cout << "v.size() = " << v.size() << endl;

    v.resize(3);

    cout << "v.capacity() = " << v.capacity() << endl;
    cout << "v.size() = " << v.size() << endl;

    //巧用swap收缩内存
    vector<int>(v).swap(v);//vector<int>(v)是通过拷贝构造创建的匿名的对象，（此时会将v中的三个元素传给匿名对象，然后匿名对象的容量比较小，大小是3）然后这个时候再和原本的v进行交换，交换后，原本的v的容量就变成了3，达到了收缩内存的效果，而匿名对象被自动释放
    cout << "v.capacity() = " << v.capacity() << endl;
    cout << "v.size() = " << v.size() << endl;

    //原理：利用自身创建一个匿名对象，并且与匿名对象交换，交换后匿名对象被释放，自身达到收缩效果
}

int main()
{
    text02();
    return 0;
}