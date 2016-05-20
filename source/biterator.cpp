#include <iostream>
#include <vector>





int main()
{
   std::vector<int> m = {1,2,3,4,5,6,7,8,9,10};
   
   auto bEndIt = m.rend();
   auto bLastIt = m.rend() - 1;
   auto bFirstIt = m.rbegin();
   
   std::cout << "*bEndIt()    = " << *bEndIt << std::endl;
   std::cout << "*bLsstIt()   = " << *bLastIt << std::endl;   
   std::cout << "*bFirstIt()  = " << *bFirstIt << std::endl;   
   
   
   auto current = m.begin();
   
   if (*current == *bLastIt) {
      std::cout << "SAME\n";
   }
   
   
   for(auto bIt = m.rbegin(); bIt!=m.rend(); bIt++) {
      std::cout << *bIt << std::endl;
   
      
   }

   
   std::cout << "**************************\n";
   for(auto it = m.end()-1; it!=m.begin()-1; it--) {
      std::cout << *it << std::endl;
   
      
   }
   
   

   return 0;
   
}