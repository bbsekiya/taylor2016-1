#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Data
{
   public:
      Data(double q) : m_Q(q) {}
      virtual ~Data() {}
      
      double q() const {
         return m_Q;
      }
   private:
      double m_Q;
};




size_t countData(const std::vector<Data>&v, double d) 
{
 
   size_t s = std::count_if(v.cbegin(), v.cend(), [&d] (const Data& m)->bool {
      return m.q() >= d;
   });
   
   return s;
   
   
}



int main()
{
   std::vector<std::string> m {
        "aaaaaaaaaa"
      , "bbb"
      , "cccccccccccccccccc"
      , "ddddddddddddddd"
      , "eeee"
    };
    
    std::stable_sort(m.begin(), m.end(), //cannot be cbegin/cend since sorting
          // [](const auto& l, const auto& r) {
            [](const std::string& l, const std::string& r) {
               return l.size() < r.size();
            });
      
   for (const auto& e : m) {
      std::cout << e << std::endl;
   }

   std::cout << "\n\n ---- Example 2 -----\n\n";
   
   std::vector<Data> d {
      Data(0.7), Data(0.9), Data(0.6), Data(0.91) };
      
   std::cout << "count = " << countData(d, 0.9) << std::endl;
   
      

   return 0;
}