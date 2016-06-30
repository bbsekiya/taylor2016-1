#include <iostream>
#include <vector>
//#include <cassert>


struct MyData {
   uint16_t    m_Data1;
   uint16_t    m_Data2;
} typedef MyData_t;

#if 0

auto ptr = reinterpret_cast<byte*>(&s);
auto buffer = vector<byte>{ptr, ptr + sizeof(s)};

#endif
template <typename T>
inline void encode (std::vector< uint8_t >& dst, const T& data)
{

    const void* pdata = &data;
    uint8_t* src = static_cast<uint8_t*>(pdata);
    
    dst.insert(dst.end(), src, src + sizeof(T));
}
int main()
{
   MyData_t    t;
   t.m_Data1 = 0x00FF;
   t.m_Data2 = 0xFF00;
   
   auto ptr = reinterpret_cast<MyData*>(&t);
   auto buffer = std::vector<MyData>{ptr, ptr + sizeof(t)};
   
   std::vector<MyData> m(buffer);
   
   std::cout << "m.size() = " << m.size() << std::endl;
   
   std::vector<uint8_t>   x2;
   char *dbuffer;
   std::copy(x2.cbegin(), x2.cend(), dbuffer);
   
  
   std::vector<char> copy1 = &t;
   
   
   return 0;
}