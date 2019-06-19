 
#include<stdio.h> 

int main() 
{ 
 
      
    
    int data = 0x11223344;
	unsigned char * ptr = (unsigned char * ) & data;
	if ( *ptr == 0x44 ) // check the value of the lower address 
		printf("little endian\n");
	else if (*ptr == 0x11)
		printf("big  endian\n");
	
	
   
    
    return 0; 
}