#include "free_list.h"
FL_HEADER* FL_remove(FL_HEADER * free_list, FL_HEADER  * block){
	FL_HEADER * temp=free_list;
	
	//search for block that matches
	while(temp!=nullptr){
		if(temp==block){
			//if found at beginning
			if(temp->prev==nullptr){
				free_list=block->next;
				free_list->prev=nullptr;
				block->next=nullptr;
				return free_list;
			}
		//if in the middle
		else if(temp->next!=nullptr&&temp->prev!=nullptr){
			block->next->prev=block->prev;
			block->prev->next=block->next;
			block->next=nullptr;
			block->prev=nullptr;
			return free_list;
			}
			//if at end
		else{
			block->prev->next=nullptr;
			block->prev=nullptr;
			return free_list;
			}
		}
		else temp=temp->next;
	}
	printf("didn't find the block!");
	return free_list;
}

FL_HEADER* FL_add(FL_HEADER * free_list, FL_HEADER * block){
	block->prev=nullptr;
	block->next=free_list;
	free_list->prev=block;
	free_list=block;
	return free_list;
}