#include <algorithm>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <iostream>
#include <vector>

#if 0
template <typename T>
void func6(T val, boost::function<void (T)>f)
{
   //std::cout << "val = " << val << std::endl;
   f(val);
   
   
}

int main()
{
   boost::function<void (int)>fnx = [](int x) { std::cout << "lambda : x = " << x << std::endl;};
   
   func6(1234, fnx);
   
   return 0;
}
#endif


template <typename T>
class St
{
   public:
      St() {}
      virtual ~St() {}
 
      void func6(T val, boost::function<T (T)>f)
      {
         //std::cout << "val = " << val << std::endl;
         T ret = val + f(val);
         std::cout  << "ret = " << ret << std::endl;
      }
      
      void func7(T val, boost::function<T (T)>f)
      {
         //std::cout << "val = " << val << std::endl;
         T ret = val + f(val);
         std::cout  << "ret = " << ret << std::endl;
      }
   private:
      T     m_Max;
      T     m_Min;
 };           


int   main()
{
   #if 0
   int value = 2;
   auto y = [=](int x) { return x + value; };
   std::cout << "y(10) = " << y(10) << std::endl;
   assert(y(10) == 12);
   #endif
   
   St<int>     s;
   int value = 2;
   s.func6(10, [=](int x) { return x + value; });
   
   
   #if 0
   int   max = 100;
   int   min = 0;
   s.func7(10, [max, min](int x) { return x + value; });
   #endif
   
   
   return 0;
}






