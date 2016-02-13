#include <iostream>
#include <assert.h>



class Plus
{
   public:
      Plus(int n) : m_N(n) {}
      
      int operator()(int n) const {
         return m_N + n;
      }
    
    private:
      int      m_N;
 };
 
 int main()
 {
   #if 0
   auto n = Plus(1);
   std::cout << "n = " << n << std::endl;
   #endif

   Plus  p(1);
   auto n = p(40);
   std::cout << "n = " << n << std::endl;
   assert(p(40) == 41);
   
  
   auto y = [value=1](int x) { return x + value; };
   std::cout << "y(10) = " << y(10) << std::endl;
   assert(y(10) == 11);
   
   
   
   
   return 0;
 }
   
   