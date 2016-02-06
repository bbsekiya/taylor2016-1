#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <string>
#include <vector>

struct IsEven
{
   bool operator()(int n) {
      return !(n % 2);
   }
};

class Plus
{
   public:
      Plus(int n) : m_N(n) {}
      
      int operator()(int n) const {
         return m_N + n;
      }
    
    private:
      int      m_N;
 };
 
class Collector
{
   public:
      Collector(){
         for (int j=0; j<10; j++) {
            m_Data.push_back(j);
         }
         //m_DataPtr = boost::make_shared<std::vector<int> >(m_Data);
      }
      virtual ~Collector() {}
      
      std::vector<int> operator()() {
            return m_Data;
      }
            
   private:
      std::vector<int> m_Data;
      //boost::shared_ptr<std::vector<int> > m_DataPtr;
};


class S1
{
   public:
      S1(std::vector<int>& v) {
         m_List = v;
         std::vector<int>::iterator it;
         for (it=m_List.begin(); it!=m_List.end(); it++) {
            std::cout << "*it = " << *it << std::endl;
          }
         
         
      }
      virtual ~S1() {}
      
   private:
      std::vector<int> m_List;
};
      


int main()
{
   Collector   c;
   
   #if 0
   boost::shared_ptr<std::vector<int> > p = c();
   std::cout << "p>size() = " << p->size() << std::endl;
   #endif
   
   

   std::vector<int> x = c();
   S1    s(x);
   
   

   #if 0
   IsEven   e;
   std::cout << "e(3) = " << e(3) << std::endl;
   
   Plus  p2(10);
   std::cout <<  "p2(20) = " << p2(20) << std::endl;
   #endif
   
   
   return 0;
}

