#include <iostream>
#include <string>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>


class Container01
{
   public:
        explicit Container01(std::string s) : m_S(s) { std::cout << "+++ constructor +++\n";}
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
  
  Container01(const Container01&& other ) : m_S("") {
         std::cout << "--- move constructor ----\n";
         m_S = other.m_S;
         m_S = "";
      }
      
   Container01& operator=(Container01&& other) {
      std::cout << "move assignment operator ---\n";
  
      if (this != &other) {     
         m_S = other.m_S;
         m_S = "";
      }
      return *this;
   }
   
   
   private:
      std::string m_S;
};
typedef boost::shared_ptr<Container01>Container01Ptr;
typedef boost::shared_ptr<const Container01>ConstContainer01Ptr;



ConstContainer01Ptr c()
{
   return boost::make_shared<Container01>("ttt");
}

Container01    c0()
{
   Container01  c("X");
   return c;
}

int main()
{
   Container01 c1("test1");
   
   Container01 c2(c1);
   Container01 c3(std::move(c1));
   
   Container01 c4 = c0();
   
  // Container01 c5 = std::string("tttt");
   
   
   #if 0
   Container01 c2 = c1;
   
   Container01 c3(c2);
   
   ConstContainer01Ptr ptr;
   
   ptr = boost::make_shared<Container01>("test");
   
   ConstContainer01Ptr ptr2 = boost::make_shared<Container01>(*ptr);
   
   ptr2 = boost::make_shared<Container01>(*c());
   
   //Container01 c4(std::move(c0()));
   
   Container01 c5(c0());
   #endif
   
   return 0;
}

      
      
      
   