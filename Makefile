project: minipro.o mess.o 
	cc minipro.o mess.o -o project
minipro.o: minipro.c minipro.h
	cc -c minipro.c 
mess.o: mess.c minipro.h
	cc -c mess.c 
clean:
	rm *.o project
