#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>


class Container01
{
   public:
       Container01(std::string s) : m_S(s) {}
      virtual ~Container01() {}
      
      
      Container01(const Container01& other ) : m_S(other.m_S) {
         std::cout << "--- copy constructor ----\n";
      }
      
      
      
       Container01& operator=(const Container01& other) {
             std::cout << "--- assignment operator ----\n";
         if (this != &other) {
            m_S = other.m_S;
         }
       
         return *this;
      }
  
  Container01(const Container01&& other ) : m_S(nullptr) {
         std::cout << "--- move constructor ----\n";
         m_S = other.m_S;
      }
   private:
      std::string m_S;
};
typedef boost::shared_ptr<Container01>Container01Ptr;
typedef boost::shared_ptr<const Container01>ConstContainer01Ptr;

#if 0
MemoryBlock(MemoryBlock&& other)
   : _data(nullptr)
   , _length(0)
{
   std::cout << "In MemoryBlock(MemoryBlock&&). length = " 
             << other._length << ". Moving resource." << std::endl;

   // Copy the data pointer and its length from the 
   // source object.
   _data = other._data;
   _length = other._length;

   // Release the data pointer from the source object so that
   // the destructor does not free the memory multiple times.
   other._data = nullptr;
   other._length = 0;
}

// Move assignment operator.
MemoryBlock& operator=(MemoryBlock&& other)
{
   std::cout << "In operator=(MemoryBlock&&). length = " 
             << other._length << "." << std::endl;

   if (this != &other)
   {
      // Free the existing resource.
      delete[] _data;

      // Copy the data pointer and its length from the 
      // source object.
      _data = other._data;
      _length = other._length;

      // Release the data pointer from the source object so that
      // the destructor does not free the memory multiple times.
      other._data = nullptr;
      other._length = 0;
   }
   return *this;
}
#endif

ConstContainer01Ptr c()
{
   return boost::make_shared<Container01>("ttt");
}

int main()
{
   Container01 c1("test1");
   
   Container01 c2 = c1;
   
   Container01 c3(c2);
   
   ConstContainer01Ptr ptr;
   
   ptr = boost::make_shared<Container01>("test");
   
   ConstContainer01Ptr ptr2 = boost::make_shared<Container01>(*ptr);
   
   ptr2 = boost::make_shared<Container01>(*c());
   
   return 0;
}

      
      
      
   