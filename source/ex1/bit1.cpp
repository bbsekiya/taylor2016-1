#include <iostream>
#include <stdio.h>


int main()
{
   uint32_t    a = 0x5A5A5A5A;
   uint32_t    b = 0xDEADBEEF;
   uint32_t    c;
   
   #if 0
   c = a | b;
   printf("c = %08x\n", c);
   
   c = a & b;
   printf("c = %08x\n", c);
   
   c = b >> 1;
   printf("c = %08x\n", c);
   
   c = b << 3;
   printf("c = %08x\n", c);
  
   #endif
   
   int32_t     x1 = 1;
   int32_t     x2 = -1;
   int32_t     c1;
   
   printf("x1 = %08x\n", x1);
   printf("x2 = %08x\n", x2);
   
   printf("c1 = %08x\n", c1);
   
   c1 = x2 >> 32;
   printf("c1 = %08x\n", c1);
  
  c1 = x1 << 1;
   printf("c1 = %08x\n", c1);
   
   c1 = x2 << 1;
   printf("c1 = %08x\n", c1);
   
   c1 = x2 << 32;
   printf("c1 = %08x\n", c1);
   
    c1 = x2 << 31;
   printf("c1 = %08x\n", c1);
   
   
}