// 260930902
// Created by jonayed islam on 1/29/2020.
//
#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "interpreter.h"
#include "shell.h"
#include "shellmem.h"
#include "kernel.h"
#include "pcb.h"
#include "cpu.h"

char *ram[1000];



int findspot(){
	int freeline = 0;
	char *selection = ram[0];
	if (selection == NULL){
		return freeline;
	}
	while (selection != NULL){
		freeline = freeline + 1;
		selection = ram[freeline];
	}
	return freeline;
}
void copy(const char *path, int aramnum)
{
    	FILE *db = fopen(path, "rt");
	if (db == NULL){
		return;
	}
        char buffer[1000];
	int ramnum = aramnum;
        while (fgets(buffer, 999, db) != NULL)
        {
            ram[ramnum] = strdup(buffer);
	    ramnum = ramnum +1; 
        }
	createpcb(aramnum,ramnum);
        fclose(db);
}
void clearram(){
	for (int i = 0; i<1000; i++){
		ram[i] = NULL;
	}
}


