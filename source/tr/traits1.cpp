#include <iostream>
#include <type_traits>

#include <string>

template <typename T>
void foo(T t, std::true_type)
{
   std::cout << t << " : integral " << std::endl << std::endl;;

}

template <typename T>
void foo(T t, std::false_type)
{

 std::cout << t << " : not integral type " << std::endl << std::endl;
}


template <typename T>
void bar(T t)
{
   foo(t, typename std::is_integral<T>::type());
}


int main()
{
   int   a = 100;
   bar(a);
   
   double b = 20.89;
   bar(b);
   
   float c = 9.9;
   bar(c);
   
   char d = 'a';
   bar(d);
   
   uint8_t e = 9;
   bar(e);
   
   uint32_t f = 999;
   bar(f);
   
   bar(std::string("xxx"));
   
   const char* o="xxx";
   bar(o);
   
   return 0;
}
