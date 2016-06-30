#include <iostream>

struct Data {
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
} typedef Data_t;

    
void func1()
{
   uint8_t d1=0x01; 
   uint8_t d2=0x02; 

   uint16_t d3 = ((uint16_t)d1 << 8) | d2;
   
   printf("d3 = %08x\n", d3);
   
   
   
}

//!!!
// TASK #1 : copy data 20-bits at at time into the Data struct   
// TASK #2 : copy data 24-bits at at time into the Data struct 
// TASK #3 : generalize #1 and #20-bits
     
int main()
{
   std::cout << "sizeof(Data_t) = " << sizeof(Data_t) << std::endl;
      
   Data_t      myData;
   
   uint32_t    value = 0x00074fd1;
   
   myData.data = (value & 0x0000FFFF);
   printf("myData.data  = %08x\n", myData.data);
   
   myData.data2 = (value >> 16) & 0x000000FF;
   printf("myData.data2 = %08x\n", myData.data2);
  
   printf("myData.type   = %08x\n", myData.type);
   printf("myData.id     = %08x\n", myData.id);
   printf("myData.parity = %08x\n", myData.parity);
   printf("myData.filler = %08x\n", myData.filler);
   
   return 0;
      
};
