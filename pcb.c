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
#include "ram.h"
#include "kernel.h"
struct PCB {
    int progcounter;
    int progstart;
    int progend;
    

};




void createpcb(int start, int end)
{
	struct PCB aPCB;
	aPCB.progcounter = 0;
	aPCB.progstart = start;
	aPCB.progend = end;
	findUpdate(aPCB);

}