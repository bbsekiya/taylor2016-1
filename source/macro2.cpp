#include <iostream>
#include <vector>

namespace test {
   template <typename T>
   void getExpectedP(std::vector<T>&input, int n1, int n2, std::vector<T>&output)
   {
      for (auto it=input.begin(); it!=input.end(); it++) {
         output.push_back(*it+n1+n2)  ; 
      }
   }
}


#define GET_EXPECTED_P  \
   test::getExpectedP \
   (                       \
        input              \
      , m_N1               \
      , m_N2               \
      , expected        \ 
   );

 
 #define GET_EXPECTED_P2(OUT)  \
   test::getExpectedP \
   (                       \
        input              \
      , m_N1               \
      , m_N2               \
      , (OUT)        \ 
   );
 
 
 
 int main()
 {
   std::vector<int> input = {1,2,3,4,5};
   int   m_N1 = 100;
   int   m_N2 = 200;
   
   std::vector<int> expected;
   
   test::getExpectedP(input, m_N1, m_N2, expected);
   
   
   std::cout << "----------------- NORMAL CALL -----------------\n";
   for (auto it=expected.begin(); it!=expected.end(); it++) {
      std::cout << "*it = " << *it << std::endl;
   }
   
   
   expected.clear();
   GET_EXPECTED_P
   
   
   std::cout << "-----------------  MACRO CALL -----------------\n";
   for (auto it=expected.begin(); it!=expected.end(); it++) {
      std::cout << "*it = " << *it << std::endl;
   }
   
   
   
   expected.clear();
   GET_EXPECTED_P2(expected)
   
   
   std::cout << "-----------------  MACRO CALL 2 -----------------\n";
   for (auto it=expected.begin(); it!=expected.end(); it++) {
      std::cout << "*it = " << *it << std::endl;
   }  
   
   
   
   double m_X1    1000;
   double m_X2    2000;
   
   
   
   return 0;
   
 }
   
   