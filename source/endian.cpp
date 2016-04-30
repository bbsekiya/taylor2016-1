#include <iostream>
#include <stdio.h>

void func(void* data)
{
   printf("data = %d\n", *(char*)data);
}

int main()
{
   int   n = 1;
   
   func(&n);
   
   return 0;

}
