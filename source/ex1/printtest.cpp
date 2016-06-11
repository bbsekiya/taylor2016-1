#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

class MyClass
{
   public:
      explicit MyClass(const std::string& s) : m_S(s) {}
      virtual ~MyClass() {}
      
      MyClass(const MyClass& that) : m_S(that.m_S) {
      std::cout << "--- copy constructor ---\n";
      }
      
     
      MyClass& operator=(const MyClass& that) {
         if (this != &that) {
            m_S = that.m_S;
            std::cout << "--- assignment operator ---\n";
         }  
         return *this;
      }
      
      MyClass(MyClass&& that) : m_S(std::move(that.m_S)) {
         std::cout << "--- move constructor ---\n";
         that.m_S = ""; //should NOT use nullptr ... undefined behavior
            
      }
      
      MyClass& operator=(MyClass&& that) {
         if (this != &that) {
            m_S = std::move(that.m_S);
            that.m_S = "";  //should NOT use nullptr ... undefined behavior
            
              std::cout << "--- move assignment operator ---\n";
         }
         return *this;
       }       
   private:
      std::string m_S;
 };
int main()
{
   
   std::vector<MyClass> m;

   //std::string t = nullptr; // NO!!
   
   MyClass  s("test");
   
   std::cout << "(1)\n";
   MyClass s2 = s;   //copy constructor  // initialization
   
    std::cout << "(2)\n";
    MyClass s3(s);    //copy constructor
  
     std::cout << "(3)\n";
    m.push_back(s);  // copy constructor
    
    std::cout << "(3.1)\n";
    s2 = s3;  // copy assignment operator
   
   std::cout << "(3.2)\n";
   MyClass x1 = std::move(s);
   
   
 

     std::cout << "(4)\n";
     m.push_back(MyClass("xxx")); //move constructor
 
 
 
   std::cout << "(5)\n";
   m.push_back(std::move(s));

 
   //MyClass s4 = std::move(s);
   
   // how to invoke assignment operator
   
   //  std::string and nullptr
   
   
   
   //MyClass  s2(std::move(s));

   
   return 0;
}