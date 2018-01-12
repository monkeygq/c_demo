#include <stdio.h>                                                                                   
void compute_a() 
{ 
	int i,j; 
	i = 0; 
	while(i < 40000000)
	{   
		j = i;
		i += 1;
	}   
}

void compute_b() 
{ 
	int i,j; 
	i = 0; 
	while(i < 10000000)
	{   
		j = i;
		i += 1;
	}   
}

int main(void) 
{ 
	while(1) {
		compute_a(); 
		compute_b();
	} 
	return 0;
}
