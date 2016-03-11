#include <iostream>
#include <sstream>
#include <fstream>

class Take2
{
   public:
       Take2(std::istream& in) {
         std::cout << "---- Take2(std::istream in) ---\n";
    
         std::string line("");
         while (std::getline(in, line)) {
            std::cout << "line = " << line << std::endl;
         }
   
       }
       
      
      
  
   private:
   
};


int main()
{
   
   
   std::cout << "\n\n ----------------------- Take2 main ------------------\n\n";

   std::ofstream of("data.txt");
   of << "0,TEST1,100\n";
      of << "1,TEST2,200\n";
         of << "2,TEST3,300\n";
   of.close();
   
   // file test
   std::cout << "\n### (1) File Test ##\n";
   std::ifstream in("data.txt");
   Take2   tt1(in);
  
    std::cout << "\n### (2) String Ttest ##\n";
   std::istringstream str("This is a test\nThat is a test2\nThat was a test3\n");
   Take2   tt2(str);
    
   return 0;
}