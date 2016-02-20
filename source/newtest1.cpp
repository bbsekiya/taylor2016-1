#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <vector>
#include <string>

void rawStringLeteralsTest()
{
   std::cout << "c:\temp" << std::endl;
   
   std::cout << R"(c:\temp)" << std::endl;
}

struct myTest
{
   int   x1;
   
   #if 1
   explicit operator bool() const {
      return true;
   }
   #endif
   
   
};
typedef boost::shared_ptr<myTest>myTestPtr;
typedef boost::shared_ptr<const myTest>ConstMyTestPtr;


void explictConverstionOperatorTest()
{
   myTestPtr p;
   
   
   p = boost::make_shared<myTest>();
   p->x1 = 100;
   
   
   //bool b = p;
   
   if (p.get()) {
      std::cout << "p ok\n";
   }
   else {
      std::cout << "p not ok\n";
   }
}

class Wow
{
   public:
      Wow() : Wow(0,0,0,0) {
         std::cout << "constructor #1\n";
      }
      explicit Wow(int n1) : Wow(n1, 0,0,0) {
         std::cout << "constructor #2\n";
      }
      
      Wow(int n1, int n2, int n3, int n4) :
         m_N1(n1), m_N2(n2), m_N3(n3), m_N4(n4) {
         std::cout << "constructor #3\n";
      }
      virtual ~Wow() {}
   
   private:
      int m_N1, m_N2, m_N3, m_N4;
};



void delegatingConstructorTest()
{
   Wow   w1;
   std::cout << "\n---------------\n";
   
   Wow   w2(100);
   std::cout << "\n---------------\n";
   
   Wow   w3(100,200,300,400);
   std::cout << "\n---------------\n";


}

void uniformInitializationTest()
{
   int   x{1234};
   std::cout << "x = " << x << std::endl;
   
  // int   y{20.4};
   
   std::vector<int> v {1,3,4,7};
   
}

void variaticTemplateTest()
{

};


int main()
{
   rawStringLeteralsTest();
   
   explictConverstionOperatorTest();
   
   delegatingConstructorTest();
   
   uniformInitializationTest();
   
   variaticTemplateTest();
   
   
   return 0;
 
 }
  
