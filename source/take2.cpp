#include <iostream>
#include <sstream>
#include <fstream>

class Take2
{
   public:
      Take2(std::string filePath) {
      
      }
      Take2() {}
      
      Take2(std::istringstream in) {
         std::cout << "---- Take2(std::istringstream in) ---\n";
         
         std::string token("");
         while (std::getline(in, token)) {
         //while (std::getline(in, token, ',')) {
           std::cout << "token = " << token << std::endl;
         }
         
      }
      
      friend std::istream& operator>>(std::istream& is, Take2& take) {
         std::string token("");
         while (std::getline(is, token, ',')) {
           std::cout << "token = " << token << std::endl;
         }
         
      }
  
   private:
   
};


int main()
{
   #if 0
   std::ostringstream   out;
   out << "This is a test\n";
   
   std::istringstream in("This is a test\n");
 
   Take2  t;
   in >> t;
   
   #endif
   std::ostringstream   out;
   out << "This is a test\n";
   Take2    t(out);

   return 0;
}