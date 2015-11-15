Project : main.o register_fir.o		
		cc *.c 

register_fir.o : header.h srting.h
		cc -Wall -c register_fir.c

main.o : main.c header.h
		cc -Wall -c main.c


