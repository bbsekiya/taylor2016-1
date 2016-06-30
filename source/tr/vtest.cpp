#include <vector>
#include <iostream>



#pragma pack(1)

struct S2 {
   char c1;  // Offset 0, no padding
   int i;    // Offset 1, no padding
   char c2;  // Offset 5, no padding
};  // sizeof(S2)==6, alignment 1

struct Data20 {
   uint32_t    m_Data:20;
} typedef Data20_t;




#pragma pop
union Data24 {
   uint32_t    m_Data:24;
} typedef Data24_t;
#pragma pack(1)  
struct MyData {
   uint16_t    m_Data;
   struct {
      uint16_t m_ContentType : 4;
      uint16_t m_Bus : 3;
      uint16_t m_Parity : 1;
      uint16_t m_Filler : 8;
   };
};
#pragma pop


  
int main()
{
   std::cout << "sizeof(S2) = " << sizeof(S2) << std::endl;

   std::cout << "sizeof(Data20) = " << sizeof(Data20) << std::endl;
   std::cout << "sizeof(Data24) = " << sizeof(Data24) << std::endl;
   std::cout << "sizeof(MyData) = " << sizeof(MyData) << std::endl;



   std::vector<Data20_t> m_Data20;
   
   
   return 0;
}