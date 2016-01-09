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


int main()
{
   MyClass     m1(100,200);
   MyClass     m2 = m1;
   MyClass     m3(std::move(test1()));
   
   MyClass&& n1 = test1();
   
   MyClass  m4(std::move(*test2()));
   
   
   return 0;
}


   
      
     