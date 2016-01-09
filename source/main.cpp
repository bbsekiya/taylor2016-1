#include <iostream>
#include "myclass.h"


MyClass  test1()
{
   MyClass  c(1,2);
   return c;
}

int main()
{
   MyClass     m1(100,200);
   MyClass     m2 = m1;
   MyClass     m3(std::move(test1()));
   
   return 0;
}


   
      
     