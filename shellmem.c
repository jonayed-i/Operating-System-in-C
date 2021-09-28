// 260930902
// Created by jonayed islam on 1/29/2020.
//
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

struct MEM
{
    char *var;
    char *val;
};

struct MEM memories[100];
int memsize = 0;
void findupdate(char *invar, char *inval)
{
    int found = 0;
    if (memsize == 0)
    {   
	char *s1 = strdup(invar);
	char *s2 = strdup(inval);
        memories[0].var = s1;
        memories[0].val = s2;
	
	
        memsize = memsize + 1;
    }
    else
    {
        for (int i = 0; i < memsize; i++)
        {
            if (strcmp(memories[i].var, invar) == 0)
            {
                found = 1;
                memories[i].val = strdup(inval);
                break;
	    }
	}
       if (found ==0){       
         
         memories[memsize].var = strdup(invar);
         memories[memsize].val = strdup(inval);
         memsize = memsize +1 ; 
       }  
        
    }
}

void printvar(char *invar)
{
	int found =0;
    for (int i = 0; i < memsize; i++)
    {
        if (strcmp(memories[i].var, invar) == 0)
        {
	    found =1; 

            printf("the value assigned to this variable is %s", memories[i].val);
            break;
        }
	
    }
    if (found == 0){
	    printf("variable not found");
    }
}


