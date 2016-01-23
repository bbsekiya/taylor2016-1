#include <iostream>
#include <boost/function.hpp>

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
