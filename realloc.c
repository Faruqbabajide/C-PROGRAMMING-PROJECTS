#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
 char  *mem_alloc;
 mem_alloc = malloc(15 * sizeof(char));
 if (mem_alloc == NULL){
 	printf ("Could not allocate requested Mecmory");
 }
  else 
  {
  	strcpy (mem_alloc, "Pan - Atlantic ");
  	
  }
  	printf ("Dynamically Allocated Memory : %s\n",mem_alloc);
  	mem_alloc= realloc(mem_alloc , 100* sizeof(char));
 if (mem_alloc == NULL){
 	printf ("Could not allocate requested Mecmory");
 }
  else 
  {
  	strcpy (mem_alloc, "memory space is extended upto 100 character");
  	
  }
  	printf ("Resized Memory : %s\n",mem_alloc);
  	free(mem_alloc);
  
	return 0;
}