#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>


class Word
{
   public:
      Word(int n) : m_N(n) {}
      virtual ~Word() {}
      
      int n() const {
         return m_N;
      }
      void setN(int n) {
         m_N = n;
      }
   private:
      int m_N;
};

typedef boost::shared_ptr<const Word> ConstWordPtr;

typedef boost::shared_ptr<std::vector<const Word> > ConstWordVectorPtr;

typedef boost::shared_ptr<const std::vector<Word> > ConstWordVectorPtr2;

typedef boost::shared_ptr<std::vector<Word> > ConstOutWordVectorPtr;


int main()
{
   Word  w1(10);
   Word  w2(20);
   
   std::vector<Word> m;
   m.push_back(w1);
    m.push_back(w2);
   
   //ConstWordVectorPtr p1 = boost::make_shared<std::vector<const Word> >();
   
   ConstWordVectorPtr2 p2 = boost::make_shared<const std::vector<Word> >(m);
   //p2->push_back(w2);
   //p2->at(0).setN(200);
   
   ConstOutWordVectorPtr outPtr = boost::make_shared<std::vector<Word> >(*p2);
   outPtr->push_back(w2);
   outPtr->at(0).setN(200);
   
   std::cout << outPtr->at(0).n() << std::endl;
   std::cout << outPtr->at(1).n() << std::endl;
   
   return 0;
}
   
   