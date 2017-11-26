/*NOTES:
 * This file (main.c) is responsible for calling the User Interface function, creating all shared resources and all necessary threads.
 * .eCos is compatible with POSIX threads (pthread), witch means that you can use both pthread_* or cyg_thread_* calls (Kernel overview p.25).
 * I really don't understand eCos workings in the computer part of the program
*/

#include <stdio.h>



int main(void){
    
    printf("Gutten tag! Welcome to SCE Link V0.1\n");
    
	return 0;
}
