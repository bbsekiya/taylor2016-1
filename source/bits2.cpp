#include <iostream>

void printBits(int n)
{
   std::cout << "Dec = " << n << std::endl;
   std::cout << "HEX = " << std::hex << n << std::endl;
   for (int j=31; j>=0; j--) {
      std::cout << ((n >> j) & 1);
   
   }
   std::cout << "\n------------------ " << std::endl;
   
}




int main()
{
   int   n1 = 0x000000FF;
   printBits(n1);
   
   int   n2 = 192;
   printBits(n2);
   
   

   return 0;
}