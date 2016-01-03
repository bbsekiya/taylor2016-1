#include <iostream>
#include <string>



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
         m_S = other.m_S;
       
         return *this;
      }
  
  
   private:
      std::string m_S;
};



int main()
{
   Container01 c1("test1");
   
   Container01 c2 = c1;
   
   Container01 c3(c2);
   
   
   return 0;
}

      
      
      
   