#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

bool compare(int a, int b)
{
	return a > b;
}


void test01()
{
    deque<int> d;
    d.push_back(10);
    d.push_back(30);
    d.push_back(20);
    d.push_front(100);
    d.push_front(300);
    cout<<"before sort: "<<endl;
    for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    sort(d.begin(),d.end());
    cout<<"after sort: "<<endl;
    for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main()
{
    test01();
    return 0;
}