#include <iostream>

#define     X1       100
const size_t X2 = 100;

int main()
{
   int   c = -1;
   
   if (X1 == c) {
      std::cout << "X1 == -1" << std::endl;
   }
   else {
      std::cout << "X1 is NOT -1" << std::endl;
   }
 
   size_t   y1 = 1;
   int      y2 = -1;
   
   if (y1 == y2) std::cout << "-----!!----\n";
   
   if (X2 == c) {
      std::cout << "X2 == -1" << std::endl;
   }
   else {
      std::cout << "X2 is NOT -1" << std::endl;
   } 
   return 0;
}


   
   
