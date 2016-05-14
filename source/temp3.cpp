#include <iostream>

template <int N>
struct MyTest1 {
   static_assert(N!=0, "N!=0");
 
   static constexpr int value = N;

   
 };



int main()
{
   std::cout << MyTest1<100>::value << std::endl;
   
   std::cout << MyTest1<0>::value << std::endl;

   return 0;
}
