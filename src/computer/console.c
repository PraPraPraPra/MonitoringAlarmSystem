/******************************************************************************
| File: console.c
|
| Autor: Fernando Silva,
|        from work by Carlos Almeida (IST) and Jose Rufino (IST/INESC), 
|        from an original by Leendert Van Doorn
|
| NOTES:
| * Handles all the console input (AKA this is the User Interface)
|
| Date:  Nov 2017
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "global.h"
#include "UIcommands.h"

/*-------------------------------------------------------------------------+
| Headers of command functions contained in this file
+--------------------------------------------------------------------------*/ 
void cmd_sos  (int, char** );

/*-------------------------------------------------------------------------+
| Variable and constants definition
+--------------------------------------------------------------------------*/ 
const char TitleMsg[] = "\n....................."\
                        "/||Application Control Monitor||\\"\
                        "..........................\n\n";

const char InvalMsg[] = "\nInvalid command!";


struct   command_d {
  void  (*cmd_fnct)(int, char**);
  char* cmd_name;
  char* cmd_help;
} const commands[] = {
  {cmd_sos,  "sos","                 help"},
  {cmd_exit, "exit","                exit"}
};



#define NCOMMANDS  (sizeof(commands)/sizeof(struct command_d))
#define ARGVECSIZE 3
#define MAX_LINE   20

/*-------------------------------------------------------------------------+
| Function: cmd_sos - provides a rudimentary help
+--------------------------------------------------------------------------*/ 
void cmd_sos (int argc, char **argv)
{
  int i;
  pthread_mutex_lock(&consoleLock);
  printf("%s\n", TitleMsg);
  for (i=0; i<(int)NCOMMANDS; i++)
    printf("%s %s\n", commands[i].cmd_name, commands[i].cmd_help);
  pthread_mutex_unlock(&consoleLock);
}

/*-------------------------------------------------------------------------+
| Function: my_getline        (called from monitor) 
+--------------------------------------------------------------------------*/ 
int my_getline (char** argv, int argvsize)
{
  static char line[MAX_LINE];
  char *p;
  int argc;

  fgets(line, MAX_LINE, stdin);

  /* Break command line into an o.s. like argument vector,
     i.e. compliant with the (int argc, char **argv) specification --------*/

  for (argc=0,p=line; (*line != '\0') && (argc < argvsize); p=NULL,argc++) {
    p = strtok(p, " \t\n");
    argv[argc] = p;
    if (p == NULL) return argc;
  }
  argv[argc] = p;
  return argc;
}

/*-------------------------------------------------------------------------+
| Function: monitor        (called from main) 
+--------------------------------------------------------------------------*/ 
void monitor (void)
{
  static char *argv[ARGVECSIZE+1], *p;
  int argc, i;
  pthread_mutex_lock(&consoleLock);
  printf("%sType sos for help\n", TitleMsg);
  pthread_mutex_unlock(&consoleLock);
  for (;;) {
    pthread_mutex_lock(&consoleLock);
    printf("\nCmd> ");
    pthread_mutex_unlock(&consoleLock);
    /* Reading and parsing command line  ----------------------------------*/
    if ((argc = my_getline(argv, ARGVECSIZE)) > 0) {
      for (p=argv[0]; *p != '\0'; *p=tolower(*p), p++);
      for (i = 0; i < NCOMMANDS; i++) 
        if (strcmp(argv[0], commands[i].cmd_name) == 0) 
          break;
      /* Executing commands -----------------------------------------------*/
      if (i < NCOMMANDS)
        commands[i].cmd_fnct (argc, argv);
      else{
        pthread_mutex_lock(&consoleLock);
        printf("%s", InvalMsg);
        pthread_mutex_lock(&consoleLock);
      }
    } /* endif my_getline */
  } /* loop forever */
}
