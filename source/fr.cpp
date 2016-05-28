#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

struct Data {
   uint64_t offset;
   int      n;
}typedef Data_t;

template <typename ITERATOR>
ITERATOR maxElement
(
     ITERATOR first
   , ITERATOR end
)
{
   ITERATOR maxIt = std::max_element(first, end, [](Data_t t1, Data_t t2)->bool {
         return t1.n < t2.n;
      });
   return maxIt;
}   
   


int main()
{
   std::vector<Data_t>    m = 
   {
      {0, 50}, {1,60}, {2, 10}, {3,60}, {4,32}
   };
   
   auto forwardMaxIt = maxElement(m.begin(), m.end());
   std::cout << "FORWARD MAX : offset = " << forwardMaxIt->offset << " n = " << forwardMaxIt->n << std::endl;
   
   auto backwardMaxIt = maxElement(m.rbegin(), m.rend());
   std::cout << "BACKWARD MAX : offset = " << backwardMaxIt->offset << " n = " << backwardMaxIt->n << std::endl;

   return 0;
}












