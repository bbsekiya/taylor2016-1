#include <ios>
#include <iostream>
#include <ostream>
#include <regex>
#include <string>


int main()
{
   //const std::regex  r("ab+c");
   const std::regex  r("ab*c");
   
  
   for (std::string s; std::getline(std::cin, s);) {
      std::cout << regex_match(s, r) << std::endl;
      std::cout << std::endl;
   
   }


   return 0;
} 
  