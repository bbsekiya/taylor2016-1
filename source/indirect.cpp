#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <string>
#include <vector>

class Parser
{
   public:
      Parser(std::string input) {]
      virtual ~Parser() {}
};

class Collector
{
   public:
      Collector(std::string file) :
         m_File(file)
      {
      }
      virtual ~Collector() {}
      
   private:
      std::string m_File;
      std::vector<int> m_Data;

      Parser   m_Parser;
};

class S1
{
   public:
      S1() {}
      virtual ~S1() {}4
      
      int doThis(int n1, int n2, int o) {
         return 0;
      }
      
};


class T1
{
   public:
      T1(boost::shared_ptr<const Collector> p = 
     