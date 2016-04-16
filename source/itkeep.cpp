#include <iostream>
#include <vector>



int main()
{
   typedef std::pair<uint32_t, double> p_t;
   std::vector<p_t> m =
      {
           {0,1.0}
         , {0,2.0}
         , {0,9.0}       
         , {0,4.0}
         , {0,5.0}
      };
   
   typename std::vector<std::vector<p_t>::iterator> elementTrack;
   
   std::vector<int> trackingPosition;
   
   for (auto it=m.begin(); it!=m.end(); it++) {
      if (it->second == 9.0) {
         trackingPosition.push_back(std::distance(m.begin(), it));
      }   
   }
   
   auto elementTrackIt = elementTrack.begin();
   std::cout << " ----------------- m ----------------\n";
   for (auto it=m.begin(); it!= m.end(); it++) {
      std::cout << it->first << " : " << it->second << std::endl;
      if (it->first == 0 && it->second == 9) {
        // if (it - m.begin()) == (elementTrack))){
            std::cout << "MATCH\n";
         }
   }
   
   std::cout << " ----------------- elementTrack ----------------\n";
   for (auto it=trackingPosition.begin(); it!= trackingPosition.end(); it++) {
      std::cout << *it << std::endl;
   }
  
   return 0;
}