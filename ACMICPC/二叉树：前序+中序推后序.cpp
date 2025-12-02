#include<iostream>
using namespace std;
string inord,preord;
int posi[256];//每个字符在中序中的位置（快速查找）
void bulid_post(int inL,int inR,int preL,int preR)
{
    if(inL>inR)
    return ;
    char root = preord[preL];//先找出root：先序的头就是
    int k = posi[root];//再找出root在中序中的位置，用于后面切割分别递归两个子树
    int leftsize = k - inL;//左子树的长度，用于递归传参

    bulid_post(inL,k-1,preL+1,preL+leftsize);//前两个是中序遍历左子树的区间范围，后两个是先序遍历左子树的区间范围
    bulid_post(k+1,inR,preL+leftsize+1,preR);//前两个是中序遍历右子树的区间范围，后两个是先序遍历右子树的区间范围
    
    cout<<root;
    
}
int main()
{
    cin>>inord>>preord;
    for(int i=1;i<=inord.size();i++)
    {
        posi[inord[i]] = i;
    }

    int n = inord.size();
    bulid_post(0,n-1,0,n-1);
    cout<<endl;


    return 0;
}
