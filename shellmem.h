#ifndef shellmem_h
#define shellmem_h
struct MEM
{
    char *var;
    char *val;
};

extern struct MEM memories[100];

void findupdate(char *invar, char *inval);
void printvar(char *invar);

#endif
