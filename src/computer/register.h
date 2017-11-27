/******************************************************************************
| File: global.h
|
| Autor: Fernando Silva,
|
| NOTES:
| * Simple heade File for global.c
|
| Date:  Nov 2017
*******************************************************************************/

#ifndef _REGISTER_H
#define _REGISTER_H
#include <stdint.h>
typedef struct reg{
	//It is defined here and not in register.c because it is a public struct
	int8_t data;
	struct reg * next;
	struct reg * ant;
}reg;

reg *createCircularBuffer(int numOfRegisters);
void deleteCricularBuffer(reg * current);

#endif
