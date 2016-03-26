#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Emphasize2
{
   public:
      explicit Emphasize2(const std::string& s) : m_S(s) {}
      virtual ~Emphasize2() {}
      
      std::string operator()(const std::string& input) const {
         return input + m_S;
       }
       
   private:
      std::string m_S;
 
};

int main()
{

 
   std::vector<std::string> v {"AAA", "BBB", "XXX"};
   
   std::transform(v.begin(), v.end(), v.begin(), Emphasize2("!!!"));
   
   for (auto it=v.begin(); it!=v.end(); it++) {
      std::cout << (*it) << std::endl;
   }
  
   
   return 0;
}
