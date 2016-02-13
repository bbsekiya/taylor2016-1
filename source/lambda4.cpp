#include <iostream>



int main()
{
  
   auto incrementBy = [](int y) {return ++y; };
   
   std::cout << incrementBy(1) << std::endl;
   
   std::cout << incrementBy(5) << std::endl;

   auto n = [](int y) {return ++y; }(100);
   std::cout << "n = " << n << std::endl;
   
   return 0;
}