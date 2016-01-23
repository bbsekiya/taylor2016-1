#include <iostream>
#include <algorithm>
#include <vector>

int main()
{

   std::vector <int> m {1,10,30,44,70,100,33,99};
   
   int   x = 30;
   
   auto lt = std::find_if(m.begin(), m.end(),
                  [x](int val) {return val == x; });
   
   if (lt != m.end()) {
      std::cout << "x = " << x  << " was found in the list\n";
   }
   
           
   
   return 0;




}