


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
#include "pcb.h"
#include "kernel.h"





struct CPU { 
	int IP; 
	char IR[1000]; 
	int quanta;
};