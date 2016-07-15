#include <map>
#include <string>
#include <iostream>

class Convert
{
public:
     Convert() : m_State(STATE::ONE)
     {
       stateMap[STATE::ONE] = &Convert::func1;
       stateMap[STATE::TWO] = &Convert::func2;
       
       transition[100] = STATE::TWO;
       transition[200] = STATE::THREE;
       
     }
     virtual ~Convert() {}
     
     enum class STATE {
         ONE, TWO, THREE, FOUR, FIVE
     };
     
     

      void put() {
         invoke(m_State, 1, 2);
      
      }
      
     void invoke(STATE state, int x, int y) {
       if(stateMap[state]) {
         (this->*stateMap[state])(x, y);
         }
       if (x == x + 1) {
       }
       
     }
     
private:
     void func1(int a, int b) { 
         std::cout << "func1" << std::endl;
     };
     void func2(int a, int b) {
             std::cout << "func1" << std::endl; 
     };
  
     
     std::map<STATE, void (Convert::*)(int, int)> stateMap;
     
     std::map<uint32_t, STATE> transition;
     
     STATE next(uint32_t d) {
         
     }
     
     STATE  m_State;
};

int main () {
   
   Convert  c;
   c.put();
   
  #if 0
  a o;
  o.invoke("func1", 1, 2);
  #endif
  
}