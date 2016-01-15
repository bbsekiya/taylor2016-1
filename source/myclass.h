#include <iostream>

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>


class MyClass
{
   public:
      explicit MyClass(int n1, int n2);
      virtual ~MyClass();
      
      MyClass(const MyClass& other);
      
      MyClass& operator=(const MyClass& other);
      
      MyClass(MyClass&& other) ;
      
      MyClass& operator=(MyClass&& other);
      
      void setN1(int n);
      void setN2(int n);
      
      int n1() const;
      int n2() const;
         
   private:
      int   m_N1;
      int   m_N2;
};
typedef boost::shared_ptr<MyClass>MyClassPtr;
typedef boost::shared_ptr<const MyClass>ConstMyClassPtr;
