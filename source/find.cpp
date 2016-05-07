#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

#if 0
auto it = std::find_if(myMap.begin(), myMap.end(), 
   [val](const std::pair<int, ValueType> & t) -> bool { 
      return t.second.x == val;
   }
);
#endif

struct timeData {
   bool completed;
   
   timeData(bool b) : completed(b) {}
};

struct realData {
   timeData h;
   timeData l;
   timeData m;
 
   realData(timeData b1, timeData b2, timeData b3) : 
      h(b1), l(b2), m(b3) {}

 };  

 
typedef struct realData realData_t;
typedef struct timeData timeData_t;
int main()
{
   #if 0
   std::map<uint32_t, realData> m =
   { {0, realData_t(timeData_t(true), timeData_t(true), timeData_t(true) }
      
   
   };
   
 auto foundItem = std::find_if(selectedItems.begin(), selectedItems.end(), 
[&i](LWItem const& item) 
{ 
return item->GetID() == i; 
});  
   
   #endif
   
   realData_t     t1(timeData_t(false), timeData_t(false), timeData_t(false));
   realData_t     t2(timeData_t(true), timeData_t(false), timeData_t(true));
    realData_t     t3(timeData_t(false), timeData_t(false), timeData_t(false));
   std::map<uint32_t, realData_t> m = {
      {0, t1}, {1, t2}, {2, t3}
      
   };
   
   bool b = false;
   
   for (auto it=m.begin(); it!=m.end(); it++) {
       b = !((it->second.h.completed == it->second.l.completed) 
      && (it->second.h.completed == it->second.m.completed)) ;
       if (b) break;
   
   }
   std::cout << "***** b = " << b << std::endl;
   
   
   #if 1
   
   auto it = std::find_if(m.begin(), m.end(), 
      [] (const std::pair<uint32_t, realData>& t) -> bool {
         return (!((t.second.h.completed == t.second.l.completed) 
         && (t.second.h.completed == t.second.m.completed))) == true;
   }
   );
   if (it == m.end()) {
      std::cout << " FALSE\n";
   }
   else {
      std::cout << " TRUE\n";
   }
   
     
  
#endif

  #if 0
   auto it = m.begin();
   for (uint32_t j=0; j<2; j++) {
   
      
      
      #if 0
       it = std::find_if(m.begin(), m.end(), 
         [j](const std::pair<uint32_t, realData_t> & t) -> bool { 
         //[&j] (const realData_t& t)->bool{ 
           // return !((t.second.h.completed == t.l.completed) && (t.h.completed == t.m.completed));
            return !((t.second.h.completed == t.second.l.completed) && (t.second.h.completed == t.second.m.completed));
            
         }
      );

      #endif
   }
   #endif
   
   //if (it!=m.end()) std::cout << "IN PROGRESS\n";
   
   return 0;
}



