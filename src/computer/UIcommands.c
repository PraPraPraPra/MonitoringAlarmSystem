/******************************************************************************
| File: UIcommands.c
|
| Autor: Fernando Silva,
|        from work by Carlos Almeida (IST)
|
| NOTES:
| * Contains all commands that can be run from the console(AKA UserInterface)
|
| Date:  Nov 2017
*******************************************************************************/

#include <stdlib.h>

/*-------------------------------------------------------------------------+
| Function: cmd_exit - gracefully terminates the application
+--------------------------------------------------------------------------*/ 
void cmd_exit (int argc, char **argv)
{
	exit(0);
}
