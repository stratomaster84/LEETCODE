#include <iostream>

using namespace std;

class A
{
public:
  int a_public;
  A(){
    a_public = 0; a_protected = 0; a_private = 0;
    cout << "Default CTOR A Started" << endl;
  }
  A(int a){
    a_public = a+2; a_protected = a+1; a_private = a;
    cout << "CTOR A Started" << endl;
  }
  void PrintA(){
    cout << a_private << ' ' << a_protected << ' ' << a_public << endl;
  }
protected:
  int a_protected;
private:
  int a_private;
};

class B : private A
{
public:
  int b_public;
  B(int b){
    b_public = b+2; b_protected = b+1; b_private = b;
    cout << "CTOR B Started" << endl;
  }
  void PrintAB(){
    PrintA();
    cout << b_private << ' ' << b_protected << ' ' << b_public << endl;
  }
protected:
  int b_protected;
private:
  int b_private;
};

class C : private B
{
public:
  int c_public;
  C(int c) : B(3){
    c_public = c+2; c_protected = c+1; c_private = c;
    cout << "CTOR C Started" << endl;
  }
  void PrintABC(){
    PrintAB();
    cout << c_private << ' ' << c_protected << ' ' << c_public << endl;
  }
protected:
  int c_protected;
private:
  int c_private;
};


int main()
{

  C c(6);
  c.PrintABC();

  return 0;
}
