bin:
	mkdir bin

time: bin
	g++ -o bin/time.out time.cpp -lncurses -fopenmp

brainfuck: bin
	g++ -o bin/brainfuck.out brainfuck.cpp

golden_section: bin
	g++ -o bin/golden_section.out golden_section.cpp

huffman: bin
	g++ -o bin/huffman.out huffman.cpp

rand-string: bin
	g++ -o bin/rand-string.out rand-string.cpp

all: time brainfuck golden_section huffman rand-string

