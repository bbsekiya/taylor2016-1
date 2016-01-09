#include <iostream>
#include "myclass.h"

MyClass::MyClass(int n1, int n2) : m_N1(n1), m_N2(n2)
{
   std::cout << "...constructor \n";
}

MyClass::~MyClass()
{
}

 
MyClass::MyClass(const MyClass& other) {
         std::cout << "--- copy constructor ----\n";
         m_N1 = other.m_N1;
         m_N2 = other.m_N2;
      }
      
MyClass& MyClass::operator=(const MyClass& other) {
         if (this != &other) {
            std::cout << "--- copy assignment operator ---\n";
            m_N1 = other.m_N1;
            m_N2 = other.m_N2;
         }
         return *this;
      }
      
      
MyClass::MyClass(MyClass&& other) : m_N1(0), m_N2(0) {
         std::cout << "--- move constructor ---\n";
         m_N1 = other.m_N1;
         m_N2 = other.m_N2;
         
         other.m_N1 = 0;
         other.m_N2 = 0;
      }
      
MyClass& MyClass::operator=(MyClass&& other) {
         std::cout << " --- move assignment opeator ----\n";
         if (this != &other) {
            m_N1 = other.m_N1;
            m_N2 = other.m_N2;
            
            other.m_N1 = 0;
            other.m_N2 = 0;
         }
         return *this;
       }
       
