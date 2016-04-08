#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <sstream>
#include <fstream>

#include <algorithm>
#include <iterator>



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
inline std::ostream&operator << (std::ostream& out, const Word& w)
{
   
   return out << w.n() << std::endl;
   
}

typedef std::vector<const Word> WordVector;
typedef boost::shared_ptr<std::vector<const Word> > WordVectorPtr;

co
class MyProcess
{
   public:
      MyProcess() {}
      virtual ~MyProcess() {}
      
      void test(WordVectorPtr p) {
         std::cout << "INPUT : p->size() = " << p->size() << std::endl;
         
         /*
         std::vector<int> from_vector(10);
    std::iota(from_vector.begin(), from_vector.end(), 0);
 
    std::vector<int> to_vector;
    std::copy(from_vector.begin(), from_vector.end(),
              std::back_inserter(to_vector));
// or, alternatively,
//  std::vector<int> to_vector(from_vector.size());
//  std::copy(from_vector.begin(), from_vector.end(), to_vector.begin());
// either way is equivalent to
//  std::vector<int> to_vector = from_vector;
 
    std::cout << "to_vector contains: ";
 
    std::copy(to_vector.begin(), to_vector.end(),
              std::ostream_iterator<int>(std::cout, " "));
    */     
         #if 1
         //!!!!!!!!!!!!! CONVERT const_iterator to iterator;
         
         WordVector::const_iterator it;
         WordVector::const_iterator itBegin = p->begin();
         WordVector::iterator outIt;// = outPtr->begin();
         WordVector     backVector;
         
         size_t t = 0;
         for (it=p->begin(); it!=p->end(); it++) {            
            
            
            if (it->n() == 50) {
               //outPtr = boost::make_shared<WordVector>(*p);
               //std::copy(itBegin, it, outIt);
               std::copy(p->begin(), p->end(), std::back_inserter(backVector));
               outPtr = boost::make_shared<WordVector>(backVector);
             
             
               Word  w = *it;
               //outPtr->push_back(*it);
               outPtr->push_back(w);
               
               
               //outPtr->at(0).setN(1222);
               
               
               
               std::cout << "outPtr->size() = " << outPtr->size() << std::endl;
               
               
               
               //outIt = outPtr->begin() + t;
           
               #if 0
               std::cout << "outIt->n() = " << outIt->n() << std::endl;
               outIt->setN(100);
               #endif
              
               
            }
            t++;
         }
         #endif
         
        
        #if 0
         for (size_t j=0; j< p->size(); j++) {
            std::cout  << p->at(j);
            
            // double * bins = new double[nbins+1]; //is this necessary?
            // std::copy( source.bins , source.bins + N, bins );
            if (p->at(j).n() == 50) {
               /*
               outPtr = boost::make_shared<WordVector>(*p);
               outPtr->push_back(p->at(j));
               */
               
           
         
         }
        #endif
         
         
      
      }
      WordVectorPtr testResult() const {
      }
      
      
   private:
      WordVectorPtr outPtr;
      
};

      
int main()
{
   WordVector  v;
   for (size_t j=0; j<10; j++) {
      v.push_back(Word(j*10));
   }
   WordVectorPtr  p = boost::make_shared<const std::vector<Word> >(v);

   MyProcess   m;
   m.test(p);
   
   
   std::cout << "--- test\n";
   Word  x(100);
   std::cout << "x = " << x << std::endl;
   
   
   return 0;
}


