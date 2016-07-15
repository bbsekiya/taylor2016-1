#include <iostream>

#include <vector>
#define __STDC_FORMAT_MACROS
#include <inttypes.h>


struct Data {
   uint16_t    data;
     struct {
         uint16_t    type: 4;
         uint16_t    id: 3;
         uint16_t    parity: 1;
         uint16_t    filler: 8;
      };
   
} typedef Data_t;

void setData(Data_t& d, uint32_t value)
{
   d.data = value & 0xFFFF;
   d.type = (value & (0xF << 16)) >> 16;
   d.id = (value & (0x3 << 20)) >> 20;
   d.parity = (value & (0x1 << 23)) >> 23;
   d.filler = (value & (0xFF << 24)) >> 24;
}


uint32_t data(Data_t& d)
{
   return d.data
         + ((uint32_t)d.type << 16)
         + ((uint32_t)d.id << 20)
         + ((uint32_t)d.parity <<  23)
         + ((uint32_t)d.filler << 24);

}

   //---------------------------------
   // ABOVE:  you must pass uint32_t, therefore construct uint32_t from 20/24 bit data and pass

void setInput20(uint32_t& value, const uint32_t& input)
{
   //uint32_t source = 0xDEADBEEF;
   
   //20-bit
   //take 20-bits out of source and concatenate to below
   //0x00 + 1 + 0 = 12-bit
   // 0000 0000 1000 0000 0000 0000 0000 0000 = 0x00800000;
   
   
   uint32_t filForWord20 = 0x00800000;
   printf("filForWord20 = %08x\n", filForWord20);
   
   value = filForWord20 | (input >> 12);
   printf("value = %08x\n", value);
   


}

void setInput24(uint32_t& value, const uint32_t& input)
{
   //uint32_t source = 0xDEADBEEF;
   
   //20-bit
   //take 20-bits out of source and concatenate to below
   //0x00 + 1 + 0 = 12-bit
   // 0000 0000 1000 0000 0000 0000 0000 0000 = 0x00800000;
   
   
   uint32_t filForWord20 = 0x00000000;
   printf("filForWord20 = %08x\n", filForWord20);
   
   value = filForWord20 | (input >> 8);
   printf("value = %08x\n", value);
   


}  
int main()
{
   #if 0
   
   long long val = (long long) mostSignificantWord << 32 | leastSignificantWord;
   printf( "%lli", val );

   #endif
   
   #if 0
   uint32_t dest;
   uint32_t in = 0xDEADBEEF;
   setInput20(dest, in);
   printf("dest = %08x\n", dest);
   
   setInput24(dest, in);
   printf("dest = %08x\n", dest);

   #endif
   
   uint64_t s1 = 0xF007000112345678;
 
   printf("val = x%" PRIx64 "\n", s1);
   
   #if 0
   uint64_t temp;
   uint32_t upper, lower;
   upper = (temp & 0xFFFFFFFF00000000) >> 32;
   lower = temp & 0x00000000FFFFFFFF;
   #endif
   
   uint32_t upper = (s1 & 0xFFFFFFFF00000000) >> 32;
   uint32_t lower = s1 & 0x00000000FFFFFFFF;
   printf("upper = %08x\n", upper);
   
    printf("lower = %08x\n", lower);
   
   //0xaf30 
   return 0;
}
   