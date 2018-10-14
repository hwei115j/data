CC := gcc

list: m_list.c list.o
	$(CC) m_list.c list.o -o m_list
stack: m_stack.c stack.o list.o
	$(CC) m_stack.c stack.o list.o -o m_stack
list.o: list.c
	$(CC) -c list.c
stack.o: stack.c
	$(CC) -c stack.c
clean:
	rm -f *.o *.exe* *.out*
