LIBS = -lm
OBJS1 = single_linklist.o
OBJS2 = doubly_linklist.o
main: $(OBJS1) $(OBJS2)
	gcc -o single_linklist $(OBJS1) $(LIBS)
	gcc -o doubly_linklist $(OBJS2) $(LIBS)
clean:
	rm -f single_linklist doubly_linklist $(OBJS1) $(OBJS2) 
