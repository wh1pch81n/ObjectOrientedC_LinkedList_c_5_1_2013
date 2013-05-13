//
//  main.c
//  LinkedList_c_5_1_2013
//
//  Created by Derrick Ho on 5/1/13.
//  Copyright (c) 2013 Derrick Ho. All rights reserved.
//

#include <stdio.h>
#include "LinkedList.h"
#include "LinkedListTestBench.h"

int main(int argc, const char * argv[])
{
	Node * n = newNode();
	n->setValue(n,35);
	n->setNext(n, NULL);
	n->setPrev(n, n);
	
	printf("%d 0x%lx 0x%lx\n", n->getValue(n),(unsigned long) n->getPrev(n), (unsigned long)n->getNext(n));
	Node * nn = newNode();
	nn->setValue(nn,39);
	nn->setNext(nn, NULL);
	nn->setPrev(nn, n);
	printf("%d 0x%lx 0x%lx\n", nn->getValue(nn),(unsigned long)  nn->getPrev(nn), (unsigned long)nn->getNext(nn));
	printf("%d 0x%lx 0x%lx\n", n->getValue(n), (unsigned long) n->getPrev(n), (unsigned long) n->getNext(n));
   
	deAllocNode(n);
	deAllocNode(nn);


	printf("should print 32:  %d\n", __LINE__);
	printf("should print time:  %s\n", __TIME__);
	printf("should print date:  %s\n", __DATE__);
	printf("should print file:  %s\n", __FILE__);
	
	List* L = newList();
	testbench(newList, deAllocList, L->pushBack, L->pushFront, L->popBack, L->popFront, L->getValueAtIndex, L->setValueAtIndex);
	
	deAllocList(L);
	//todo need to test linked list
	//while (1);
	return 0;
}

