#include <map>
#include <string>
#include <iostream>

class a
{
public:
     a()
     {
       pointerMap["func1"] = &a::func1;
       pointerMap["func2"] = &a::func2;
     }

     void invoke(const std::string& name, int x, int y) {
       if(pointerMap[name])
         (this->*pointerMap[name])(x, y);
     }

private:
     void func1(int a, int b) { 
         std::cout << "func1" << std::endl;
     };
     void func2(int a, int b) {
             std::cout << "func1" << std::endl; 
     };
     std::map<std::string, void (a::*)(int, int)> pointerMap;
};

int main () {
  a o;
  o.invoke("func1", 1, 2);
}