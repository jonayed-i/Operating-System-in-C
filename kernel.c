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
#include "cpu.h"
#include "pcb.h"


struct RQ {
    struct PCB data;
    struct RQ *next;

};


struct RQ *head = NULL;
struct RQ *tail = NULL;

void findUpdate(struct PCB input){
    struct RQ *n = head;

    int nodeFound = 0;
    if (head == NULL){
        head = (struct RQ *) malloc(sizeof(struct RQ));
        head->data = input;
        head->next = NULL;
	tail = head;
    }
    else{
        while (n != NULL) {
            struct RQ *current = n;
            n = n->next;
            if (n == NULL){
                struct RQ *aNode;
                aNode = (struct RQ *) malloc(sizeof(struct RQ));

                if (aNode == NULL) exit(1);

                aNode->data = input;
        
                aNode->next = NULL;
                current->next = aNode;
		tail = aNode;

            }

        }
    }
}

/*my init function done in the modules*/
void scheduler() {
    struct CPU maincpu = *(struct CPU *) malloc(sizeof(struct CPU));
    struct RQ *n = head;
    int o = 0;
    while (n != NULL) {
        int startram = n->data.progstart;
        int endram = head->data.progend;

        for (int i = startram; i < endram; i++) {
            maincpu.IR[o++] = ram[i];
            interpreter(maincpu.IR);
        }

    }
}






int main(){
	shellUI();
	

}
