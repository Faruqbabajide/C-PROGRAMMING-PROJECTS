#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
 char  *mem_alloc;
 mem_alloc = calloc(15 * sizeof(char));
 if (mem_alloc == NULL){
 	printf ("Could not allocate requested Mecmory");
 }
  else 
  {
  	strcpy (mem_alloc, "Pan - Atlantic ");
  	
  }
  	printf ("Dynamically Allocated Memory : %s\n",mem_alloc);
  	free(mem_alloc);
  
	return 0;
}