#include"list_algos.h"


int comp(ListNode *listnode){
	ListNode *current=listnode;
	ListNode *next = current->next;
	
	int current_value = *((int*)current->value);
	int next_value = *((int*)next->value);
	
	if(current_value>next_value) return 1;//如果当前比下一个大，则需要互换
	else return 0;//比下一个小，不用换
}

List *bubble_sort(List* list){
	int count = list->count;
	if(count==0){
		printf("No data in this link-list");
		return NULL;
	}
	else if(count==1){
		printf("Only one data in this link-list, no need to do bubble sort");
		return NULL;
	}
	else if{
		int sert_num = 0;
		int small_count = 0;
		ListNode* current = list->first;
		
		while(count--){
			while(current->next!=NULL){
				if(comp(current){
					ListNode *next = current->next;
					current->next = next->next;
					next->prev = current->prev;
					current->prev = next;
					next->next = current;
				}
				current = next;
			}
		}
		return list;
	}
}






