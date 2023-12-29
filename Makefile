all: testDriver.o Merkle.o node.o person.o person1.o
	g++ -Wall testDriver.o Merkle.o node.o person.o person1.o -o output.out

Merkle.o: Merkle.cpp
	g++ -Wall -c Merkle.cpp

node.o: node.cpp
	g++ -Wall -c node.cpp

person.o: person.cpp
	g++ -Wall -c person.cpp

person1.o: person1.cpp
	g++ -Wall -c person1.cpp

testDriver.o: testDriver.cpp
	g++ -Wall -c testDriver.cpp


run:
	./output.out

val:
	valgrind ./output.out

clean: 
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
