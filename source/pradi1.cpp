#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

class MyClass
{
   public:
      MyClass(int n) : m_N(n) {}
      virtual ~MyClass() {}
      int n() const {
         return m_N;
      }
   private:
      int m_N;
};

const MyClass& func1()
{
   boost::shared_ptr<const MyClass> p = boost::make_shared<const MyClass>(100);
   const MyClass& r = *p;
   return r;
}

int main()
{
   MyClass p = func1();
   std::cout << "p.n() = " << p.n() << std::endl;
   
   return 0;
}
