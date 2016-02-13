#include <iostream>
#include <vector>
#include <algorithm>

struct IsEven
{
   bool operator()(int n) {
      return !(n % 2);
   }
};

class IsMultilple
{
   public:
      IsMultilple(int n) : m_N(n) {}
      virtual ~IsMultilple() {}
      
      bool operator()(int s) {
         return !(s % m_N);
      }
   private:
      int m_N;
};


int main()
{
   std::vector<int> m {1,20,4,5,7,100,8,99,98,102,40};
   
   size_t c = 0;
   c = count_if(m.begin(), m.end(), IsEven());
   std::cout << "c = " << c << std::endl;
 
   c = count_if(m.begin(), m.end(), [](int n) {return !(n % 2);});
   std::cout << "c = " << c << std::endl;
  
  c = count_if(m.begin(), m.end(), IsMultilple(3));
  std::cout << "multiple:c = " << c << std::endl;
  
  c = count_if(m.begin(), m.end(), [value=3](int n) { return !(n % value); });
  std::cout << "multiple:c = " << c << std::endl;

  
  
   return 0;
   
   
   
   
 }