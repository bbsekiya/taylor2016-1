#include <iostream>

#include <vector>


struct Data {
   uint16_t    data;
     struct {
         uint16_t    type: 4;
         uint16_t    id: 3;
         uint16_t    parity: 1;
         uint16_t    filler: 8;
      };
   
} typedef Data_t;



struct Data2 {
   uint16_t    data;
  

   union {
      uint16_t data2;

   
      struct {
         uint16_t    type: 4;
         uint16_t    id: 3;
         uint16_t    parity: 1;
         uint16_t    filler: 8;
      };
   };
} typedef Data_t2;

    
void func1()
{
   uint8_t d1=0x01; 
   uint8_t d2=0x02; 

   uint16_t d3 = ((uint16_t)d1 << 8) | d2;
   
   printf("d3 = %08x\n", d3);
   
   
   
}


void func2()
{
   Data_t2      myData;
   
   uint32_t    value = 0x00074fd1;
   
   myData.data = (value & 0x0000FFFF);
   printf("myData.data  = %08x\n", myData.data);
   
   myData.data2 = (value >> 16) & 0x000000FF;
   printf("myData.data2 = %08x\n", myData.data2);
  
   printf("myData.type   = %08x\n", myData.type);
   printf("myData.id     = %08x\n", myData.id);
   printf("myData.parity = %08x\n", myData.parity);
   printf("myData.filler = %08x\n", myData.filler);
   
   myData.type = 0x7;
   myData.id = 0x0;
   myData.parity = 0x00;
   myData.filler = 0x00;
   
   printf("\n\nmyData.type   = %08x\n", myData.type);
   printf("myData.id     = %08x\n", myData.id);
   printf("myData.parity = %08x\n", myData.parity);
   printf("myData.filler = %08x\n", myData.filler);
   printf("myData.data2 = %08x\n", myData.data2);
   
   
};



#if 0

You should never rely on how the compiler lays out your structure in memory. There are ways to do what you want with a single assignment, but I will neither recommend nor tell you.



static inline void to_id(struct CPUid *id, uint32_t value)
{
    id->Stepping         = value & 0xf;
    id->Model            = (value & (0xf << 4)) >> 4;
    id->FamilyID         = (value & (0xf << 8)) >> 8;
    id->Type             = (value & (0x3 << 12)) >> 12;
    id->Reserved1        = (value & (0x3 << 14)) >> 14;
    id->ExtendedModel    = (value & (0xf << 16)) >> 16;
    id->ExtendedFamilyID = (value & (0xff << 20)) >> 20;
    id->Reserved2        = (value & (0xf << 28)) >> 28;
}

And the opposite

static inline uint32_t from_id(struct CPUid *id)
{
    return id->Stepping
         + ((uint32_t)id->Model << 4)
         + ((uint32_t)id->FamilyID << 8)
         + ((uint32_t)id->Type << 12)
         + ((uint32_t)id->Reserved1 << 14)
         + ((uint32_t)id->ExtendedModel << 16)
         + ((uint32_t)id->ExtendedFamilyID << 20)
         + ((uint32_t)id->Reserved2 << 28);
}

#endif



void func3()
{
   Data_t      myData;
   
   std::vector<uint8_t> m;
   uint32_t    value = 0x00074fd1;
   
   
   m.reserve(sizeof(value));
   for (size_t i = 0; i < sizeof(value); ++i) {
      if (i>0) {
         m.push_back(value & 0xFF);
         value >>= 8;
      }
   }  
 
   std::cout << "m.size() = " << m.size() << std::endl;
   for (auto it=m.cbegin(); it!=m.cend(); it++) {
      uint8_t x = *it;
      printf("x = %x\n", x);
   }
}
 
   


   
//!!!
// TASK #1 : copy data 20-bits at at time into the Data struct   
// TASK #2 : copy data 24-bits at at time into the Data struct 
// TASK #3 : generalize #1 and #20-bits
     
int main()
{
   std::cout << "sizeof(Data_t) = " << sizeof(Data_t) << std::endl;
   
   
   func3();
   
   return 0;
      
};
