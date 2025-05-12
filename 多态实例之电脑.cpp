#include<iostream>
using namespace std;

class cpu
{
    public:
    virtual void caculate()=0;
};

class videocard
{

    public:
    virtual void display()=0;
};

class memory
{
    public:
    virtual void storage()=0;
};

//
class computer
{
    public:
    cpu* my_cpu;
    videocard* my_videocard;
    memory* my_memory;

    computer(cpu* cpu,videocard* videocard,memory* memory)
    {
        this->my_cpu=cpu;
        this->my_videocard=videocard;
        this->my_memory=memory;
    };

    void dowork()
    {
        this->my_cpu->caculate();
        this->my_videocard->display();
        this->my_memory->storage();
    }

    // ~computer()
    // {
    //     if(this->my_cpu!=NULL)
    //     {
    //         delete this->my_cpu;
    //         this->my_cpu=NULL;
    //     }

    //     if(this->my_memory!=NULL)
    //     {
    //         delete this->my_memory;
    //         this->my_memory=NULL;
    //     }

    //     if(this->my_videocard!=NULL)
    //     {
    //         delete this->my_videocard;
    //         this->my_videocard=NULL;
    //     }

    // }
};

class intelcpu:public cpu
{
    public:
    void caculate()
    {
        cout<<"intelcpu begin caculate"<<endl;
    }

    
};

class intelvideocard:public videocard
{
    public:
    void display()
    {
        cout<<"intelvideocard begin display"<<endl;
    }

    
};

class intelmemory:public memory
{
    public:
    void storage()
    {
        cout<<"intelmemory begin storage"<<endl;
    }
};



class lenvoncpu:public cpu
{
    public:
    void caculate()
    {
        cout<<"lenvoncpu begin caculate"<<endl;
    }

    
};

class lenvonvideocard:public videocard
{
    public:
    void display()
    {
        cout<<"lenvonvideocard begin display"<<endl;
    }

    
};

class lenvonmemory:public memory
{
    public:
    void storage()
    {
        cout<<"lenvonmemory begin storage"<<endl;
    }
};


void text01()
{
    cpu* intelc = new intelcpu;
    videocard* intelv = new intelvideocard;
    memory* intelm = new intelmemory;


    computer* c1 = new computer(intelc,intelv,intelm);
    c1->dowork();
    delete c1;

cout<<"--------------------------"<<endl;

    cpu* lenvonc = new lenvoncpu;
    videocard* lenvonv = new lenvonvideocard;
    memory* lenvonm = new lenvonmemory;


    computer* c2 = new computer(lenvonc,lenvonv,lenvonm);
    c2->dowork();
    delete c2;


}
int main()
{
    text01();
    return 0;
}