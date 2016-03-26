#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>


class MyClass
{
   public:
      MyClass(int n1, int n2) : m_N1(n1), m_N2(n2) {}
      virtual ~MyClass() {}
      
      int n1() const {
         return m_N1;
      }
      
      int n2() const {
         return m_N2;
      }
   private:
      int m_N1;
      int m_N2;
 };
 
 int main()
 {
   MyClass  m(100, 200);
   //int   (MyClass::pfunc)() = &MyClass::n1();


    return 0;
 }
 
 
      