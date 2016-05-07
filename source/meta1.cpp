#include <limits>
#include <iostream>


template <int N>
struct Abs {
   static_assert(N != INT_MIN, "INT_MIN");
   static constexpr int value = (N < 0) ? -N : N;
};



int main()
{
   
   Abs<-77>    a;
   std::cout << "a.value = " << a.value << std::endl;
   
  
   std::cout << "--- Abs<-202>::value = " << Abs<-202>::value << std::endl;
   
   
   const int n = -200;
   std::cout << " n = " << n << std::endl;
   std::cout << "--- Abs<n>::value = " << Abs<n>::value << std::endl;
   
   
   return 0;
}