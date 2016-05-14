#include <iostream>

template <uint32_t M, uint32_t N>
struct func {
   static const uint32_t value = func<M, M%N>::value;
};


template <uint32_t M>
struct func<M, 0> {
   static_assert(M!=0, "M!=0");
   static constexpr uint32_t value = M;
};


#if 0
void myFunc(int n)
{
   static_assert(n!=0, "n != 0");
   
   std::cout << "myFunc(" << n << ")\n";
}
#endif


template <int N>
struct MyTest
{
   static_assert(N!=0, "n != 0");
   
  // std::cout << "myFunc(" << N << ")\n";
};






int main()
{

   std::cout << func<3,10>::value << std::endl;
   
   std::cout << func<1,10>::value << std::endl;
  
   //myFunc(100);
   
   return 0;
}