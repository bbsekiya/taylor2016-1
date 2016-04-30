#include <iostream>

bool areSame(bool a, bool b, bool c)
{
   return (a == b) && (a == c);
} 



int main()
{
   std::cout << "areSame(true, true, true) = " << areSame(true, true, true) << std::endl;
   
   std::cout << "areSame(false, false, false) = " << areSame(false, false, false) << std::endl;
   
   std::cout << "areSame(true, true, false) = " << areSame(true, true, false) << std::endl;
  

   std::cout << "areSame(true, false, false) = " << areSame(true, false, false) << std::endl;  
   
   std::cout << "areSame(false, true, false) = " << areSame(true, true, false) << std::endl;
   
     std::cout << "areSame(true, false, true) = " << areSame(true, false, true) << std::endl;  
 
      std::cout << "areSame(false, true, true) = " << areSame(false, true, true) << std::endl;  
      
      return 0;
}