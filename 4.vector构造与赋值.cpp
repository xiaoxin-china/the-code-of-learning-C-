#include<iostream>
#include<vector>
using namespace std;
//vector动态内存大小的底层原理：
//vector底层是一个数组，当数组容量不够的时候，会重新申请一块更大的内存空间，然后把原数组中的元素拷贝到新空间中，释放原空间
//vector的动态扩展机制，并不是以两倍进行扩展，大约是以1.5倍进行扩展

/*构造：
vector<T> v1                        默认构造
vector<T> v2(v1.begin(),v1.end())   传入v1的从begin到end的元素，前闭后开，包含begin不包含end
vector<T> v3(n,element)             传入n个element
vector<T> v4(const vector<T>& v)    拷贝构造
*/

void prientvector(vector<int> &v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}

void text01()
{
    vector<int> v1;//默认构造
    int arr[] = {1,2,3,4,5,6};
    
    vector<int> v2(arr,arr+sizeof(arr)/sizeof(int));
     prientvector(v2);

    vector<int> v3(v2.begin(),v2.end());
    prientvector(v3);

    vector<int> v4(10,100);
    prientvector(v4);

    vector<int> v5(v4);
    prientvector(v5);
}

/*赋值：
vector &operator=(const vector<T>& v)           重载等号操作符
assign(v1.begin(),v1.end())                     将v1的从begin到end的元素赋值给v
assign(n,element)                               赋值n个element
*/

void text02()
{
    vector<int> v1(10,100);
    vector<int> v2=v1;          //重载等号赋值
    prientvector(v2);

    vector<int> v3;
    v3.assign(v2.begin(),v2.end());    //assign赋值
    prientvector(v3);



}
int main()
{
    text02();
    return 0;
}