#ifndef LOL
#define LOL
#include <stdio.h>

typedef struct fl_header{
	int length;
	fl_header* next;
	fl_header* prev;
} FL_HEADER;

FL_HEADER* FL_remove(FL_HEADER * free_list, FL_HEADER  * block);

FL_HEADER* FL_add(FL_HEADER * free_list, FL_HEADER * block);
#endif