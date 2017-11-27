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
#ifndef _GLOBALS
#define _GLOBALS

#include <pthread.h>

extern pthread_mutex_t consoleLock;//To keep consistency when writing to console

#endif