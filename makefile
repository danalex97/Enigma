# edit this makefile so that running make compiles your enigma program

enigma: Main.o Plugboard.o Reflector.o Rotor.o Pipeline.o Enigma.o Parser.o Component.o
	g++ -std=c++11 $^ -o $@

Main.o: Main.cpp 
	g++ -std=c++11 -c $^ -o $@

Enigma.o: Enigma.cpp 
	g++ -std=c++11 -c $^ -o $@

Pipeline.o: Pipeline.cpp 
	g++ -std=c++11 -c $^ -o $@

Plugboard.o: Plugboard.cpp 
	g++ -std=c++11 -c $^ -o $@

Reflector.o: Reflector.cpp
	g++ -std=c++11 -c $^ -o $@

Rotor.o: Rotor.cpp
	g++ -std=c++11 -c $^ -o $@

Parser.o: Parser.cpp
	g++ -std=c++11 -c $^ -o $@

Component.o: Component.cpp
	g++ -std=c++11 -c $^ -o $@

clean:
	rm -rf enigma *.o

.PHONY: clean
