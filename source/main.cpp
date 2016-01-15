#include <iostream>
#include "myclass.h"

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

MyClass  test1()
{
   MyClass  c(1,2);
   std::cout << "\n --- test1() constructor just called...\n";
   return c;
}

MyClassPtr  test2()
{
   MyClassPtr p = boost::make_shared<MyClass>(100,1000);
   return p;
}

ConstMyClassPtr test3(int n1, int n2)
{
   MyClassPtr p = boost::make_shared<MyClass>(n1, n2);
   p->setN1(122);
   return p;
}




int main()
{
   MyClass     m1(100,200);
   MyClass     m2 = m1;
   MyClass     m3(std::move(test1()));
   
   MyClass&& n1 = test1();
   
   MyClass  m4(std::move(*test2()));
   
   std::vector<ConstMyClassPtr> v1;
   
   std::cout << "\n---------------- vector test -----\n";
   
   
   v1.push_back(test2());
   
   ConstMyClassPtr&& p = test3(7,8);
   v1.push_back(std::move(test3(7,8)));
   
   return 0;
}


   
      
     