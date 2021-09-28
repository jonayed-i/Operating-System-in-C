mykernel: shell.o interpreter.o shellmem.o cpu.o kernel.o ram.o pcb.o
	cc -o mysh shell.o interpreter.o shellmem.o cpu.o kernel.o ram.o pcb.o



shell.o: shell.c
	cc -c shell.c 

interpreter.o: interpreter.c
	cc -c interpreter.c

shellmem.o: shellmem.c
	cc -c shellmem.c

cpu.o: cpu.c
	cc -c cpu.c

pcb.o: pcb.c
	cc -c pcb.c

kernel.o: kernel.c
	cc -c kernel.c

ram.o: ram.c
	cc -c ram.c


clean:
	rm *.o mysh
