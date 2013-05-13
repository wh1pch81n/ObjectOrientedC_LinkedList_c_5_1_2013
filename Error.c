//
//  Error.c
//  LinkedList_c_5_1_2013
//
//  Created by Derrick Ho on 5/2/13.
//  Copyright (c) 2013 Derrick Ho. All rights reserved.
//

#include "Error.h"
#include <stdio.h>
#include <stdlib.h>
void ErrorWithMSG(const char* msg){
	printf("%s \n", msg);
	exit(0);
}

void ErrorWithMSGWithLineNumber(const char* msg, unsigned int linenumber){
	printf("Error on Line %d\n\t", linenumber);
	ErrorWithMSG(msg);
}