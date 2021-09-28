//
// Created by joisl on 1/31/2020.
//

//#ifndef PCB_H
//#define PCB_H
struct PCB {
    int progcounter;
    int progstart;
    int progend;
    struct ACCOUNT *next;

};

void createpcb(int start, int end);
//#endif //PCB_H
