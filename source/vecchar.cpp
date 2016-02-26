#include <iostream>
#include <vector>
#include <stdio.h>


int main()
{
   std::vector<char> v {10,11,12,13,14};
   
  
   printf("v[0] = %x\n", v[0]);
   printf("v[0] = %d\n", v[0]);
   
   char* const first = v.data();
   char* const last = v.data() + v.size() - 1;
   
   printf("first = %x\n", (*first));
   printf("first = %d\n", (*first));  
   printf("last = %x\n", (*last));
   printf("last = %d\n", (*last));   
   
   
   unsigned long long f = 4000000000L;
   unsigned long   long l = 5000000000L;
  std::cout << "f = " << f << std::endl;
  
  std::cout << "f + l = " << f + l << std::endl;
  
      
   return 0;
}
   
   