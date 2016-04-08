#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

#include <vector>

class Base
{
   public:
      Base(int n1) : m_N1(n1) {
          std::cout << "----- Base() ----\n";
     }
     
     #if 0
     virtual ~Base() {
         std::cout << "----- virtual ~Base() ----\n";
      }
     #endif
      
      #if 1
      ~Base() {
         std::cout << "----- ~Base() ----\n";
      }
      #endif
     
   private:
      int   m_N1;
};
typedef boost::shared_ptr<Base>BasePtr;
typedef boost::shared_ptr<const Base>ConstBasePtr;


class Derived: public Base
{
   public:
      Derived(int n1, int n2) : Base(n1), m_N2(n2) {
        std::cout << "---- Derived() -----\n";
      }
      virtual ~Derived() {
         std::cout << "---- ~Derived() -----\n";
      }
      
   private:
      int   m_N2;
};
typedef boost::shared_ptr<Derived>DerivedPtr;
typedef boost::shared_ptr<const Derived>ConstDerivedPtr;


class Tr1 : public std::vector<std::string>
{
   public:
      Tr1(std::string n) 
      {
       std::cout << "----- Tr1 ----\n";
       push_back(n);
      }
      virtual ~Tr1() {
         std::cout << "----- ~Tr1 ----\n";
      }
 };
typedef boost::shared_ptr<Tr1>Tr1Ptr;
typedef boost::shared_ptr<const Tr1>ConstTr1Ptr;
  
 typedef boost::shared_ptr<std::vector<std::string> >VectorStringPtr;
 typedef boost::shared_ptr<const std::vector<std::string> >ConstVectorStringPtr;
  
int main()
{
   //Base  b(100);
   
   //Derived  d(1,2);
   
   //ConstBasePtr   b_ptr = boost::make_shared<const Base>(100);
   
   //ConstBasePtr   b_ptr = boost::make_shared<const Derived>(100,200);
 
   //Tr1   t1("test");
   
   //ConstVectorStringPtr v_ptr = boost::make_shared<const std::vector<std::string> >();
   
   //ConstVectorStringPtr v_ptr1 = boost::make_shared<const Tr1>("sss");
   
   #if 0
   std::vector<std::string>*p = new Tr1("sss");
   delete p;
   #endif
   
   
   #if 0
   Base *p = new Derived(100,200);
   delete p;
   #endif
   

   return 0;
}