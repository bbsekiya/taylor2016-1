#include <iostream>
#include <vector>
#include <boost/tuple/tuple.hpp>







  template <typename T1>
  struct inputData {
      uint32_t source;
      uint64_t offset;
      T1   value;
   } ;


template <typename T1>
void tAndInputCheck
(
    std::vector<std::pair<uint64_t, T1> >& t
  , std::vector<inputData<T1> >& input
  , std::vector<std::pair<size_t, T1> >& t_change
 )
 {
  auto tIt = t.begin();
    
  for (size_t j=0; j<input.size(); j++) {
  
   
      if (input[j].source == 0 && input[j].offset == tIt->first) {
         if (input[j].value != tIt->second) {
            t_change.push_back(std::make_pair(j, tIt->second));
          }
         tIt++;
      } 
   }
 
 }

int main()
{
   std::vector<std::pair<uint64_t, double> > t =
      {
         {0,1.0}, {1,2.0}, {2,5.0}
      };

   struct inputData<double> input[] = { 
                     {0,0,1.0}, {0,1,2.0}, {0,2,3.0}, {0,3,4.0}
           };
 
   size_t sizeOfInput = sizeof(input)/sizeof(inputData<double>);
   
   std::vector<inputData<double> > inputVector;
   
   for (size_t j=0; j<sizeOfInput; j++) {
      inputVector.push_back(input[j]);
   }
   
   std::vector<std::pair<size_t, double> > t_change;
   
   tAndInputCheck(t, inputVector, t_change);

   for (auto it = t_change.begin(); it!=t_change.end(); it++) {
      std::cout << it->first << " : " << it->second << std::endl;
   
   }
   
   
   
   #if 0
   auto tIt = t.begin();
   
   for (size_t j=0; j<sizeOfInput; j++) {
      if (input[j].source == 0 && input[j].offset == tIt->first) {
         if (input[j].value != tIt->second) {
            t_change.push_back(std::make_pair(j, tIt->second));
         }
      } 
   }
      
   #endif
   
   
   return 0;
}