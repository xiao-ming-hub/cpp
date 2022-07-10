all: time brainfuck golden-section rand-string

clean:
	if [ -e bin ]; then rm bin -rf; fi

bin:
	mkdir bin

cube-scrambling: cube-scrambling.cpp
	g++ -o bin/cube-scrambling cube-scrambling.cpp

time: bin time.cpp
	g++ -o bin/time time.cpp -lncurses -fopenmp

brainfuck: bin brainfuck.cpp
	g++ -o bin/brainfuck brainfuck.cpp

golden-section: bin golden-section.cpp
	g++ -o bin/golden-section golden-section.cpp

rand-string: bin rand-string.cpp
	g++ -o bin/rand-string rand-string.cpp

