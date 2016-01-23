#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void func1(T t)
{
   t *= 2;
}

template <typename T>
void func2(const T t)
{
   //t *= 2;
}


template <typename T>
void func3(T& t)
{
   t *= 2;
}


void x(int&& n)
{
   std::cout << "x(int&& " << n << ")\n";
}

void x(const int& n)
{
   std::cout << "x(int& " << n << ")\n";
}




template <typename T>
void func4(T&& t)
{
   x(std::forward<T>(t));
   
   x(std::move(t));
}

int main()
{
   const int n = 10;
   func1(n);
   
   func2(100);
   
   int m = 10;
   func3(m);
   std::cout << "\n-------\n";
   func4(100);
   
   std::cout << "\n-------\n";
   func4(m);
   
   return 0;
}