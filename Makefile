CC=g++
OPTS=-c --std=c++14 -O2

all: my_prog

run : my_prog
	./my_prog

test: my_prog test.py
	python3 test.py

my_prog: main.o calc.o list.o exception.o
	$(CC) -o my_prog $^

main.o: main.cpp calc.h
	$(CC) main.cpp $(OPTS)

calc.o: calc.cpp list.o exception.o calc.h
	$(CC) calc.cpp $(OPTS)

list.o: list.cpp
	$(CC) list.cpp $(OPTS)

exception.o: exception.cpp
	$(CC) exception.cpp $(OPTS)

clean:
	rm -rf *.o *.dSYM my_prog