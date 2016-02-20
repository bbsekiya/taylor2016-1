#include <iostream>
#include <sstream>
#include <fstream>

class Take
{
   public:
      Take(std::string filePath) {
      
      }
      Take() {}
      
      Take(std::istringstream in) {
         
         std::string token("");
         while (std::getline(in, token)) {
         //while (std::getline(in, token, ',')) {
           std::cout << "token = " << token << std::endl;
         }
         
      }
      
      friend std::istream& operator>>(std::istream& is, Take& take) {
         std::string token("");
         while (std::getline(is, token, ',')) {
           std::cout << "token = " << token << std::endl;
         }
         
      }
  
   private:
   
};


int main()
{
   
   std::ostringstream   out;
   out << "This is a test\n";
   
   std::istringstream in("This is a test\n");
 
   Take  t;
   in >> t;
   
   

   return 0;
}