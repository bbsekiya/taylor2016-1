#include <iostream>
#include <string>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <fstream>
#include <sstream>
#include <ostream>

class BaseObject
{
   public:
      BaseObject(int n1) : m_N1(n1) {}
      virtual ~BaseObject() {}
   
   std::string toString() const {
      std::stringstream  s;
      
      
      s << "Data" << "," << m_N1 
      << std::endl;
      
      return s.str();
   }
   private:
      int   m_N1;
};

inline std::ostream&operator <<
(
     std::ostream& out
   , const BaseObject& b
)
{
   return out << b.toString();
}

template <typename T>
class Derived : public BaseObject
{
   public:
      Derived(int n1, T s) : BaseObject(n1), m_T1(s) {
      }
      virtual ~Derived(){}
      
   private:
      T     m_T1;
};


class Analyze
{
   public:
      Analyze(const std::vector<BaseObject>& v) {
         for (auto it=v.begin(); it!=v.end(); it++) {
            std::cout << "*it = " << *it;
         }
      }
   Analyze(const std::vector<std::string>& v) {
         for (auto it=v.begin(); it!=v.end(); it++) {
            std::cout << "*it = " << *it;
         }
      }     
};


int   main()
{
   Derived<std::string>  d1(100, "TEST1");
   Derived<std::string>  d2(200, "TEST1");
   std::vector<BaseObject> m { d1, d2 };
   
   std::vector<std::string>  m2 { "333,Test1\n", "444,Test2\n" };
   Analyze        a(m2);
   


   return 0;
}