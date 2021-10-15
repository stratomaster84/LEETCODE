#include <iostream>

using namespace std;

class A{
public:
  A(){cout<<"A+"<<endl;}
  virtual void func() = 0;
  virtual void func2() = 0;
  ~A(){cout<<"A-"<<endl;}
};

class B:public A{
public:
  B(){cout<<"B+"<<endl;}
  //void func(){cout<<"B func"<<endl;}
  virtual void func2(){cout<<"B func2"<<endl;}
  ~B(){cout<<"B-"<<endl;}
};
class C:public B{
public:
  C(){cout<<"C+"<<endl;}
  void func(){cout<<"C func"<<endl;}
  void func2(){cout<<"C func2"<<endl;}
  ~C(){cout<<"C-"<<endl;}
};

int main()
{
  B *a;
  C c;
  a = &c;
  a->func();
  a->func2();

  return 0;
}
