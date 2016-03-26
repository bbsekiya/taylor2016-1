#include <iostream>
#include <vector>
#include <string>
#include <algorithm>




void funcTest1()
{
   std::cout << "\n-------- funcTest1() -----------\n";
   
   std::vector<int> m1 {1,2,3,4,5,6};
   int   a = 100;
   int*pa = &a;
   int& b = a;
   
   std::cout << "a = " << a << " *pa = " << *pa << " b = " << b << std::endl;
}


void funcTest2()
{
   std::cout << "\n-------- funcTest2() -----------\n";
   std::vector<int> m1 {1,2,3,4,5,6};
   std::vector<int> m2 {1,2,3,4,5,6};
   std::vector<int> m3 {1,2,3,7,8,9};
   std::vector<int> m4 {1,2,3,4,5,6,7};
   
   std::vector<size_t> m5 {1,2,3,4,5,6};
   
   std::cout << "m1 == m2 : " << (m1 == m2) << std::endl;
   std::cout << "m1 == m3 : " << (m1 == m3) << std::endl;
   std::cout << "m1 == m4 : " << (m1 == m4) << std::endl;
   //std::cout << "m1 == m5 : " << (m1 == m5) << std::endl;  

   #if 0
   if (std::equal(v1.begin(), v1.begin() + n, v2.begin())
      std::cout << "success" << std::endl;
   #endif
   
   
   if (std::equal(m4.begin(), m4.end() -2, m1.begin())) {
      std::cout << "OK\n";
   }
   else {
      std::cout << "NO!\n";
   }
  if (std::equal(m5.begin(), m5.end(), m1.begin())) {
      std::cout << "OK2\n";
   }
   else {
      std::cout << "NO2!\n";
   }
    
   
}



void funcTest3()
{
   std::vector<std::string> m {"12345", "abcdef", "aaaaaaaa", "xxx", "1234567890", "00000000" };
   
  size_t cnt = 0; 
  //std::for_each(v.begin(), v.end(), f);

  std::for_each(m.begin(), m.end(), [&cnt](std::string n) {
      if (n.size() > 5) cnt++; });
 
  
  std::cout << "cnt = " << cnt << std::endl;
}

                                       


int main()
{
   funcTest1();
   
   funcTest2();
   
   funcTest3();
   
   
   return 0;
}






