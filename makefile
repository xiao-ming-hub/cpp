bin:
	mkdir bin

time: bin
	g++ -o bin/time time.cpp -lncurses -fopenmp

brainfuck: bin
	g++ -o bin/brainfuck brainfuck.cpp

golden-section: bin
	g++ -o bin/golden-section golden-section.cpp

rand-string: bin
	g++ -o bin/rand-string rand-string.cpp

all: time brainfuck golden-section rand-string

