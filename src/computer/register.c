/******************************************************************************
| File: global.c
|
| Autor: Fernando Silva,
|
| NOTES:
| * All things Circular Buffer related are implemented here
| * Functions:
| * *createCircularBuffer(int numOfRegisters)
| * *deleteCircularBuffer(reg *currentReg)
| * INCOMPLETE!
|
| Date:  Nov 2017
*******************************************************************************/
#include <stdint.h> //Is already in "register.h"
#include "register.h"
#include <stdlib.h>
#include "global.h"

reg *createCircularBuffer(int numOfRegisters){//Creates a circular Bufefer (based on a double linked list)
	
	int i;
	reg *current, *aux, *first;
	current = NULL;
	aux = NULL;
	first = NULL;
	
	if(numOfRegisters-->0){
		current = (reg*)malloc(sizeof(reg));
		current->data = 0;
		current->next = NULL;
		current->ant = NULL;
		first = current;
	}
	
	for(i=0;i<numOfRegisters;i++){
		aux = (reg*)malloc(sizeof(reg));
		aux->data = 0;
		aux->next = NULL;
		aux->ant = current;
		current = aux;
	}
	first->next= current;
	current->ant = first;
	
	return current;
	
}

void deleteCricularBuffer(reg * current){//Erase all the registers from memory
	reg * aux;
	if(current==NULL)
		return;
	if(current->ant!=NULL)
		(current->ant)->next = NULL;
	
	aux = current;
	
	
	while(current->next!=NULL){
		current = current->next;
		free(aux);
		aux = current;
	}
}
