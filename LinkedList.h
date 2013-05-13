//
//  LinkedList.h
//  LinkedList_c_5_1_2013
//
//  Created by Derrick Ho on 5/1/13.
//  Copyright (c) 2013 Derrick Ho. All rights reserved.
//

#ifndef LinkedList_c_5_1_2013_LinkedList_h
#define LinkedList_c_5_1_2013_LinkedList_h
#include "Node.h"



typedef struct List{
	Node* head;
	Node* tail;
	unsigned int size;
	void (*pushBack)(struct List* this, nodeValType n);
	void (*popBack)(struct List* this );
	void (*pushFront)(struct List* this, nodeValType n);
	void (*popFront)(struct List* this);
	nodeValType (*getValueAtIndex)(struct List* this ,unsigned int index);
	void (*setValueAtIndex)(struct List* this, unsigned int index, nodeValType n);
} List;

/**constructor */
List* newList();
/**destructor*/
void deAllocList(List* L);


#endif
