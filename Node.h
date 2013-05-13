//
//  Node.h
//  LinkedList_c_5_1_2013
//
//  Created by Derrick Ho on 5/1/13.
//  Copyright (c) 2013 Derrick Ho. All rights reserved.
//

/**Node class API*/

#ifndef LinkedList_c_5_1_2013_Node_h
#define LinkedList_c_5_1_2013_Node_h

typedef int nodeValType ;
typedef struct Node{
	//member variables
	nodeValType value;
	struct Node* next;
	struct Node* prev;
	//public Member functions
	void (*setValue)(struct Node* this,  nodeValType val);
	void (*setNext)(struct Node* this,  struct Node* next);
	void (*setPrev)(struct Node* this,  struct Node* prev);
	nodeValType (*getValue)(struct Node* this);
	struct Node* ( *getPrev)(struct Node* this);
	struct Node* ( *getNext)(struct Node* this);
}Node;

//the functions listed below are considered public
/**constructor*/
Node* newNode();
/**destructor*/
void deAllocNode(Node*);

#endif
