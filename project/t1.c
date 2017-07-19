#include <stdio.h>                                                                                   
void longa() 
{ 
  int i,j; 
  i=0; 
  while(i<1000000)
  {   
    j=i;
    i+=1;
  }   
} 

void foo2() 
{ 
  int i=0;  
  while(i<10)
  {   
    longa();
    i+=1;
  }   
} 

void foo1() 
{ 
  int i=0;  
  while(i<100)
  {   
    longa();
    i+=1;
  }   
} 

int main() 
{ 
  foo1(); 
  foo2(); 
}

