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





//You should never rely on how the compiler lays out your structure in memory. 

struct CPUID          
    {
          uint32_t   Stepping         : 4;         
          uint32_t   Model            : 4;        
          uint32_t   FamilyID         : 4;        
          uint32_t   Type             : 2;        
          uint32_t   Reserved1        : 2;         
          uint32_t   ExtendedModel    : 4;         
          uint32_t   ExtendedFamilyID : 8;          
          uint32_t   Reserved2        : 4;          
    }typedef CPUID_t;


//static  void to_id(struct CPUid *id, uint32_t value)
static  void to_id(CPUID_t& id, uint32_t value)
{
  
    id.Stepping         = value & 0xf;
    id.Model            = (value & (0xf << 4)) >> 4;
    id.FamilyID         = (value & (0xf << 8)) >> 8;
    id.Type             = (value & (0x3 << 12)) >> 12;
    id.Reserved1        = (value & (0x3 << 14)) >> 14;
    id.ExtendedModel    = (value & (0xf << 16)) >> 16;
    id.ExtendedFamilyID = (value & (0xff << 20)) >> 20;
    id.Reserved2        = (value & (0xf << 28)) >> 28;;
}


static  void to_id2(CPUID_t& id, uint32_t value)    
{
    id.Stepping         = value & 0xf;
    id.Model            = (value >> 4) & 0xf;
    id.FamilyID         = (value >> 8) & 0xf;
    id.Type             = (value >> 12)& 0x3;
    id.Reserved1        = (value >> 14) & 0x3;
    id.ExtendedModel    = (value >> 16) & 0xF;
    id.ExtendedFamilyID = (value >> 20) & 0xFF;
    id.Reserved2        = (value >> 28) & 0xFF;
   
    
}

//And the opposite

static  uint32_t from_id(CPUID_t& id)
{
    return id.Stepping
         + ((uint32_t)id.Model << 4)
         + ((uint32_t)id.FamilyID << 8)
         + ((uint32_t)id.Type << 12)
         + ((uint32_t)id.Reserved1 << 14)
         + ((uint32_t)id.ExtendedModel << 16)
         + ((uint32_t)id.ExtendedFamilyID << 20)
         + ((uint32_t)id.Reserved2 << 28);
}





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
 
   

void func4()
{
   uint32_t    value = 0xDEADBEEF;
   
   printf("value  = %08x\n", value);
   
   CPUID_t  id;
   
   to_id(id, value);
   
   
    printf("id.Stepping         = %04x\n", id.Stepping);
    printf("id.Model            = %04x\n", id.Model);
    printf("id.FamilyID         = %04x\n", id.FamilyID);
    printf("id.Type             = %04x\n", id.Type);
    printf("id.Reserved1        = %04x\n", id.Reserved1);
    printf("id.ExtendedModel    = %04x\n", id.ExtendedModel);
    printf("id.ExtendedFamilyID = %04x\n", id.ExtendedFamilyID);
    printf("id.Reserved2        = %04x\n", id.Reserved2);
    
   uint32_t value2 = from_id(id);
   printf("values2 = %08x\n", value2);  
   
   std::cout << "\n\n";
   
   
   to_id2(id, value);
   
   
    printf("id.Stepping         = %04x\n", id.Stepping);
    printf("id.Model            = %04x\n", id.Model);
    printf("id.FamilyID         = %04x\n", id.FamilyID);
    printf("id.Type             = %04x\n", id.Type);
    printf("id.Reserved1        = %04x\n", id.Reserved1);
    printf("id.ExtendedModel    = %04x\n", id.ExtendedModel);
    printf("id.ExtendedFamilyID = %04x\n", id.ExtendedFamilyID);
    printf("id.Reserved2        = %04x\n", id.Reserved2);  
    value2 = from_id(id);
     
   printf("values2 = %08x\n", value2);  
   
   uint32_t x = 0xFFFFFFFF;
   
   printf("************ %08x\n", (0xf << 4));
};

   
//!!!
// TASK #1 : copy data 20-bits at at time into the Data struct   
// TASK #2 : copy data 24-bits at at time into the Data struct 
// TASK #3 : generalize #1 and #20-bits
     
int main()
{
   std::cout << "sizeof(Data_t) = " << sizeof(Data_t) << std::endl;
   
   
   //func3();
   
   func4();
   
   
   return 0;
      
};
