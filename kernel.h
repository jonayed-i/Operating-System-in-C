//
// Created by joisl on 1/31/2020.
//

#ifndef KERNEL_H
#define KERNEL_H
struct RQ {
    struct PCB *data;
    struct RQ *next;

};

void findUpdate(struct PCB input);
void scheduler();
#endif //CPU_H
