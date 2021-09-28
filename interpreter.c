// 260930902
// Created by jonayed islam on 1/29/2020.
//
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "kernel.h"
#include "shell.h"
#include "shellmem.h"
#include "ram.h"
#include "pcb.h"



int interpreter(char *words[100]){
    char *cmd = words[0];
    char *quit = "quit";
    char *arg1 = words[1];
    char *arg2 = words[2];
    char *arg3 = words[3];
    //printf("arg1 %d, arg2 %d, arg3 %d", strcmp(arg1,"dad"),strcmp(arg2,"john"),strcmp(arg3,"test"));
   //rintf("you entered{%s}\n", cmd);
    //intf("{%s}\n", arg1);
    
    if (strcmp(cmd, "help\n") == 0)
    {
        printf("the possible commands are help, quit, set VAR STRING, print VAR, run SCRIPT.txt");
    }

    else if (strcmp(cmd, "quit") == 10)
    {
        printf("BYE");
        return 2;
    }
    else if (strcmp(cmd, "set") == 0)
    {
        findupdate(arg1, arg2);
    }
    else if (strcmp(cmd, "print") == 0)
    {
        printvar(arg1);
    }
    else if (strcmp(cmd, "run") == 0)
    {
	   //rintf("congrats");
        
	FILE *db = fopen(arg1, "rt");
        char buffer[1000];
        while (fgets(buffer, 999, db))
        {
            parseInput(buffer);
        }
        fclose(db);
    }
    else if (strcmp(cmd, "exec") == 0)
    {
	int spot1 = findspot();	           
	copy(arg1,spot1);
	int spot2 = findspot();	           
	copy(arg2,spot2);
	int spot3 = findspot();	           
	copy(arg3,spot3);
	scheduler();


    }


    else
    {
        printf("UNKNOWN COMMAND");
    }

    return 0;
}
