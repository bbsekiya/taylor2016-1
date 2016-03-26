#include <iostream>
#include <string>

class Emphasize
{
   public:
      explicit Emphasize(const std::string& s) : m_S(s) {}
      virtual ~Emphasize() {}
      
      std::string s() const {
         std::cout << "....s() called \n";
         return m_S;
       }
       
   private:
      std::string m_S;
 
};

void  myFunc(Emphasize e)
{
   std::cout << "s() = " << e.s() << std::endl;
}
 
int   main()
{
   //Emphasize("abc");
   
   Emphasize   e("ABC");
   myFunc(e);
   
  
   //myFunc(std::string("WOW"));
   
   Emphasize   e2 = std::string("THAT");
   myFunc(e2);
   
   
   
   
   
   
   
   
   return 0;
 }