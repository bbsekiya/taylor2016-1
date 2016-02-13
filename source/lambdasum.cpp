#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
   std::vector<int> m { 1,10,100,200,9};
   
   int sum = 0;
   for_each (m.begin(), m.end(), [&sum](int n) { sum+=n; });
   
   std::cout << "sum = " << sum << std::endl;
   
   
 
   return 0;
}