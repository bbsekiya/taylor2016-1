#include <iostream>




int main()
{
   int j=7;
   
   [j](int v) { v+=j; 
               std::cout << "v = " << v << std::endl; } (10);
               
   return 0;
}
