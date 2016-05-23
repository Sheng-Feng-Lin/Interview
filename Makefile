LIBS = -lm
OBJS1 = single_linklist.o
main: $(OBJS1)
	gcc -o single_linklist $(OBJS1) $(LIBS)
clean:
	rm -f single_linklist $(OBJS1) 
