//
//  Node.c
//  LinkedList_c_5_1_2013
//
//  Created by Derrick Ho on 5/1/13.
//  Copyright (c) 2013 Derrick Ho. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Node.h"

/**Implementation file.  Users of node class should not
have direct access to this file.*/

/*class methods.  Only accessible via the Node Struct*/
static void setValue( Node* this,  nodeValType value ){ this->value = value;}
static void setNext( Node* this,   Node* next){ this->next = next;}
static void setPrev( Node* this,   Node* prev){ this->prev = prev;}
static nodeValType getValue( Node* this){ return this->value;}
static Node* getPrev( Node* this ){ return this->prev;}
static Node* getNext( Node*  this){ return this->next;}


Node* newNode(){
	Node* obj = malloc( sizeof(Node));
	
	//init member variables
	obj->value =(typeof(obj->value)) NULL;
	obj->next = NULL;
	obj->prev = NULL;
	
	//init methods
	obj->setValue = setValue;
	obj->setNext = setNext;
	obj->setPrev = setPrev;
	obj->getValue = getValue;
	obj->getPrev = getPrev;
	obj->getNext = getNext;
	
	return obj;
}
void deAllocNode(Node* this){
	free(this);
}