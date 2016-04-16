#include <iostream>


template <typename T>
void binary(T n)
{
   std::cout << n << " = ";
   for (int j=sizeof(T)*8 -1; j>=0; j--) {
      std::cout << (n >> j) % 2;
  
      // 13 = 8 + 4 + 0 + 1 = 1101
      // 4  =     4 + 0 + 0 = 0100

   }
   std::cout << std::endl;
   
}



int main()
{
   
   #if 0
   binary(int(4));
   binary(int(13));
   
   int   n = 13;
   
   std::cout << std::hex << n << std::endl;
   std::cout << std::dec << n << std::endl;
   #endif
   
   int n = 13;
   
   std::cout << "Original : " << std::endl;
   binary(n);
   std::cout << std::endl;
   
   std::cout << "left-shfited  (1) : " << std::endl;
   binary(n<<1);
   std::cout << std::endl;
   
   std::cout << "left-shfited  (2) : " << std::endl;
   binary(n<<2);
   std::cout << std::endl; 
   
   std::cout << "left-shfited  (3) : " << std::endl;
   binary(n<<3);
   std::cout << std::endl; 
   
   
   
   
   
   std::cout << "right-shfited  (1):  "<< std::endl;
   binary(n>>1);
   std::cout << std::endl;
   
   std::cout << "right-shfited (2) :  "<< std::endl;
   binary(n>>2);
   std::cout << std::endl;
     
   return 0;
}

   