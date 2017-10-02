typedef struct fl_header{
	int length;
	fl_header* next;
	fl_header* prev;
} FL_HEADER;

void FL_remove(FL_HEADER * free_list, FL_HEADER  * block);

void FL_add(FL_HEADER * free_list, FL_HEADER * block);