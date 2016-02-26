#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <vector>


class Process
{
   public:
      Process() {}
      virtual ~Process() {}
      
      void put(const std::vector<int>& v) {
      
         m_OutputPtr = boost::make_shared<std::vector<int> >(v);
         
         std::cout << "--- put(ref)----\n";
         std::vector<int>::const_iterator it;
         for (it=v.begin(); it!=v.end(); it++) {
            std::cout << "(*it) = " << (*it) << std::endl;
         }
         
         for (const auto& s : v) {
            std::cout << "s = " << s << std::endl;
         }
         
          std::cout << "--- put(ref) end ----\n\n\n";
      }
      
      void put(const boost::shared_ptr<const std::vector<int> > p) {
      
         //m_OutputPtr = p;
         
         std::cout << "--- put(ptr)----\n";
         std::vector<int>::const_iterator it;
          for (it=p->begin(); it!=p->end(); it++) {
            std::cout << "(*it) = " << (*it) << std::endl;
         }
         
         for (const auto& s : (*p)){
            std::cout << "s = " << s << std::endl;
         }
          std::cout << "--- put(ptr) end ----\n\n\n";         
      }
     
     
      
      
   private:
      boost::shared_ptr<std::vector<int> > m_OutputPtr;

};


int main()
{
   std::vector<int> m {10,20,30,40,50};
   
   Process     p1;
   p1.put(m);
   
   boost::shared_ptr<std::vector<int> > mptr =
      boost::make_shared<std::vector<int> >(m);
      
   p1.put(mptr);
   
   
   return 0;
}
   

      
      
