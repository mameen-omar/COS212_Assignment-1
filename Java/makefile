.SUFFIXES: .java .class

.java.class:
	javac *.java
    
CLASSES = \
	Tester.java \
	CircularList.java \
	Stack.java \
	Queue.java \
	Deque.java

default: classes

classes: $(CLASSES:.java=.class)

run: classes
	java Tester

clean:
	$(RM) *.class