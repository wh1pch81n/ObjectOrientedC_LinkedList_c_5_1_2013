//
//  LinkedList.c
//  LinkedList_c_5_1_2013
//
//  Created by Derrick Ho on 5/1/13.
//  Copyright (c) 2013 Derrick Ho. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Error.h"

static void pushBack( List* this, nodeValType n){
	this->size += 1;
	Node * temp = newNode();
	temp->value = n;
	if (!this->head) { //empty list
		this->head = temp;
		this->tail = temp;
	}else{
		temp->prev = this->tail;
		this->tail->next = temp;
		this->tail = temp;
	}
}
static void popBack( List* this ){
	switch (this->size) {
		case 0:break;
		case 1:
			deAllocNode(this->tail);
			this->head = this->tail = NULL;
			this->size = 0;
			break;
		default:
			this->tail = this->tail->prev;
			deAllocNode(this->tail->next);
			this->tail->next = NULL;
			this->size -= 1;
	}
}
static void pushFront( List* this, nodeValType n){
	this->size += 1;
	Node * temp = newNode();
	temp->value = n;
	if (!this->tail) { //empty list
		this->head = temp;
		this->tail = temp;
	}else{
		temp->next = this->head;
		this->head->prev = temp;
		this->head = temp;
	}
}
static void popFront( List* this ){
	switch (this->size ) {
		case 0:break;
		case 1:
			deAllocNode(this->head);
			this->head = this->tail = NULL;
			this->size = 0;
			break;
		default:
			this->head = this->head->next;
			deAllocNode(this->head->prev);
			this->head->prev = NULL;
			this->size -= 1;
	}
}
static Node* getNodeFromList(List* this, unsigned int index){
	if (index >= this->size) {
		ErrorWithMSGWithLineNumber("List index Out of Bounds\n", __LINE__);
	}
	Node* cursor = this->head;
	int i;
	for (i = 0; i < index; ++i) {
		cursor = cursor->getNext(cursor);
	}
	return cursor;
}
static nodeValType getValueAtIndex( List* this, unsigned int index){
	Node* cursor = getNodeFromList(this, index);
	return cursor->getValue(cursor);
}
static void setValueAtIndex( List* this, unsigned int index, nodeValType n){
	Node* cursor = getNodeFromList(this, index);
	cursor->setValue(cursor, n);
}

List* newList(){
	List * this = malloc(sizeof(List));
	*this =(List){
		.head = NULL,
		.tail= NULL,
		.size= 0,
		.pushBack = pushBack,
		.popBack = popBack,
		.pushFront = pushFront,
		.popFront = popFront,
		.getValueAtIndex = getValueAtIndex,
		.setValueAtIndex = setValueAtIndex
	};
	return this;
}
void deAllocList(List* L){
	//popUntil empty
	while (L->size) {
		L->popBack(L);
	}
	//dealloc list
	free(L);
}

