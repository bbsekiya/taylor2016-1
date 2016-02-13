#include <iostream>

int func(int n)
{
   static int x = 0;
   return ++x + n;
}


class MyFunc
{
   public:
      MyFunc() {}
      virtual~MyFunc() {}
      
      int func(int n) {
         static int m = 0;
        
         return ++m + n;

      }
      const static int x = 0;
      
};

template <typename T>
T func2(T n)
{
   static T x = 0;
   return ++x + n;
}




int main()
{
   std::cout << "func(10) = " << func(10) << std::endl;
   std::cout << "func(10) = " << func(10) << std::endl;
   
   MyFunc   m;
   std::cout << "m.func(10) = " << m.func(10) << std::endl;
   std::cout << "m.func(10) = " << m.func(10) << std::endl;
    
   std::cout << "func2(10) = " << func2(10) << std::endl;
   std::cout << "func2(10) = " << func2(10) << std::endl;
   
   auto x = func2(100);
   std::cout << "x = " << x << std::endl;
   
 
   return 0;
 }