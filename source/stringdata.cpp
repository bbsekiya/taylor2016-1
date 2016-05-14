#include <iostream>
#include <string>
#include <vector>



int main()
{
   std::vector<std::string> data =
      {
      /*
           "DATA1,100,2:10,NONE"
         , "DATA2,200,3:10,INDEX"
      */
           { "DATA1,100,2:10,NONE" }
         , { "DATA2,200,3:10,INDEX" }
        
      };
      
   std::cout << "data.size() = " << data.size() << std::endl;
   
   for (auto it=data.begin(); it!=data.end(); it++) {
      std::cout << *it << std::endl;
   }
   return 0;
}
  
