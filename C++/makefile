OBJECTS = CircularList.o Stack.o Queue.o Deque.o

main: main.C $(OBJECTS)
	g++ -static main.C $(OBJECTS) -o main

CircularList.o: CircularList.C CircularList.h
	g++ -static -c CircularList.C
	
Stack.o: Stack.C Stack.h CircularList.h
	g++ -static -c Stack.C
	
Queue.o: Queue.C Queue.h
	g++ -static -c Queue.C
	
Deque.o: Deque.C Deque.h
	g++ -static -c Deque.C
	
run: main
	./main
	
clean:
	rm -f main *.o