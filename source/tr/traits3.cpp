#include <iostream>
#include <type_traits>

template <typename T, typename U>
void typeCheck(T t, U u)
{
   if ( std::is_same<T, U>::value) {
      std::cout <<  "same type\n";
   }
   else {
      std::cout << "NOT the same type\n";
   }
}

class A {
};

class B {

};

class C : public A {
};

int main()
{
   typeCheck(10,20);
   
   uint16_t x1 = 0xDEAD;
   uint32_t x2 = 0xDEADBEEF;
   typeCheck(x1, x2);
   
   uint16_t x3 = 1;
   uint16_t x4 = 2;
   typeCheck(x3, x4);  
 
   uint16_t x5 = 1;
   uint32_t x6 = 2;
   typeCheck(x5, x6);   
   
   A     a;
   B     b;
   C     c;
   typeCheck(a, a);
   typeCheck(a, b);
   typeCheck(a, c);
   
   return 0;
}