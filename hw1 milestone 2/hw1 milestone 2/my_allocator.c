/* 
    File: my_allocator.c

    Author: <your name>
            Department of Computer Science
            Texas A&M University
    Date  : <date>

    Modified: 

    This file contains the implementation of the module "MY_ALLOCATOR".

*/

/*--------------------------------------------------------------------------*/
/* DEFINES */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* INCLUDES */
/*--------------------------------------------------------------------------*/

#include<stdlib.h>
#include "my_allocator.h"
#include "free_list.h"

/*--------------------------------------------------------------------------*/
/* DATA STRUCTURES */ 
/*--------------------------------------------------------------------------*/

static char* first;
static int remaining;
FL_HEADER* free_list1;
/*--------------------------------------------------------------------------*/
/* CONSTANTS */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* FORWARDS */
/*--------------------------------------------------------------------------*/

    /* -- (none) -- */

/*--------------------------------------------------------------------------*/
/* FUNCTIONS FOR MODULE MY_ALLOCATOR */
/*--------------------------------------------------------------------------*/

/* Don't forget to implement "init_allocator" and "release_allocator"! */

unsigned int init_allocator(unsigned int _basic_block_size, 
			    unsigned int _length){
	first=(char*)malloc(_length);
	free_list1=(FL_HEADER*)first;
	remaining=_length;
	free_list1->length=length;
	free_list1->next=nullptr;
	free_list1->prev=nullptr;
	
	//if error, return 0
	return 0;
}

void release_allocator(){
	free(first);
}

Addr my_malloc(size_t _length) {
  /* This preliminary implementation simply hands the call over the 
     the C standard library! 
     Of course this needs to be replaced by your implementation.
  */
  FL_HEADER* temp=free_list1;
  while(temp->length < _length && temp != nullptr){
	  temp=temp->next;
  }
  if(temp==0){
	  fprint("out of memory");
	  return 0;
  }
  if(temp->length >= _length){
	  FL_remove(free_list1,temp);
  }
  remaining-=_length;
}

int my_free(Addr _a) {
	FL_HEADER* temp=(FL_HEADER*)_a;
	FL_add(free_list1,temp);
  return 0;
}

