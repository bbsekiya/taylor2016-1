#include <iostream>



int main()
{
   //[](int n) { std::cout << n << std::endl;}(10);
   
   
   []() { std::cout << "Hello World!\n" << std::endl;}();
   
   auto hello = []() { std::cout << "Hello World!\n" << std::endl;};
   hello();
   return 0;
}