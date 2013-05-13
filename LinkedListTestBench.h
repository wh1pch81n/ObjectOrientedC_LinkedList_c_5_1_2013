//
//  LinkedListTestBench.h
//  LinkedList_c_5_1_2013
//
//  Created by Derrick Ho on 5/4/13.
//  Copyright (c) 2013 Derrick Ho. All rights reserved.
//

#ifndef LinkedList_c_5_1_2013_LinkedListTestBench_h
#define LinkedList_c_5_1_2013_LinkedListTestBench_h

void printList(List* L){
	int i;
	for (i = 0; i < L->size; ++i) {
		printf("%d, ", L->getValueAtIndex(L, i));
	}printf("\n");
}

void testbench(
			   List* (*constructor)(),
			   void (*destructor)(List* condemned),
			   void (*pushBack)(List* this, nodeValType n),
			   void (*pushFront)(struct List* this, nodeValType n),
			   void (*popBack)(struct List* this ),
			   void (*popFront)(struct List* this),
			   nodeValType (*getValueAtIndex)(struct List* this ,unsigned int index),
			   void (*setValueAtIndex)(struct List* this, unsigned int index, nodeValType n)
			   )
{
	printf("create list of 5 numbers...\n");
	List* first_list = constructor();
	int i;
	for (i = 0; i < 5; ++i) {
		first_list->pushBack(first_list, i + 50);
	}
	printList(first_list);
	printf("make copy list...\n");
	List* second_list = constructor();
	for(i = 0; i < first_list->size; ++i){
		second_list->pushBack(second_list, first_list->getValueAtIndex(first_list, i));
	}
	printf("1st L: "); printList(first_list);
	printf("2nd L: "); printList(second_list);
	printf("pop front and back of 1st...\n");
	first_list->popBack(first_list);
	first_list->popFront(first_list);
	printf("1st L: "); printList(first_list);
	printf("2nd L: "); printList(second_list);
}

#endif
