#include<iostream>
using namespace std;
string inord,preord;
int posi[256];//每个字符在中序中的位置（快速查找）


void bulid_post(int inL,int inR,int preL,int preR)
{
    if(inL>inR)
    return ;
    char root = preord[preL];//根在前序开头
    int k = posi[root];//根在中序的位置
    int leftSize = k - inL;//左子树节点数

    bulid_post(inL,k-1,preL+1,preL+leftSize);//递归处理左子树
    bulid_post(k+1,inR,preL+leftSize+1,preR);//递归处理右子树
    cout<<root;
}



int main()
{
    cin>>inord>>preord;
    for(int i = 0;i<inord.size();i++)
    {
        posi[inord[i]] = i;
    }

    int n = inord.size();
    bulid_post(0,n-1,0,n-1);
    cout<<endl;
    return 0;
}