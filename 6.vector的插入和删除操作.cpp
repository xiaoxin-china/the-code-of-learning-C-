#include<iostream>
#include<vector>
using namespace std;
//插入：
//push_back(ele)  :尾插入
//insert(const_iterator pos, ele)  :迭代器位置插入
//insert(sonst_iterator pos, int count, ele)  :迭代器位置插入count个ele


//删除：
//pop_back()  :尾删除
//erase(const_iterator pos)  :迭代器位置删除元素
//erase(const_iterator start, const_iterator end)  :迭代器位置删除[start, end)区间的元素
//clear()  :清空迭代器中所有元素

void printVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void test01()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    vector<int>::iterator it = v.begin();
    v.insert(it,100);//最头上，第一个位置插入，也就是相当于插在原先pos位置元素的前面

    printVector(v);//100 10 20 30 40 50

    v.insert(it, 2, 666);//在迭代器位置it处插入2个666

    printVector(v);//666 666 100 10 20 30 40 50

    v.pop_back();
    printVector(v);//666 666 100 10 20 30 40

    //想删除第二个666
    v.erase(it + 1);//2号位置删除元素
    printVector(v);//666 100 10 20 30 40

    //想删除100 10
    v.erase(it+1, it+3 );//前闭后开，所以应该是从it+1开始，到it+3结束
    printVector(v);//666 20 30 40


    v.clear();//清空
    printVector(v);//
}

int main()
{
    test01();
    return 0;
}