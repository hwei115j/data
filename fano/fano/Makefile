all: encoding.c func.o fano.h
	gcc encoding.c func.o fano.h -o code
func.o : func.c fano.h
	gcc -c func.c fano.h
clean:
	rm -f *.exe *.o *.gch *.stackdump
	
