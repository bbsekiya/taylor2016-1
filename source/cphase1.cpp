//#include <iostream>
//#include <stdlib.h>


int main()
{
   //std::cout << "this is a test\n";

   void *p = malloc(100 * sizeof(char));
   free(p);
   return 0;
}

