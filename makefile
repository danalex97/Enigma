# edit this makefile so that running make compiles your enigma program

enigma: Main.o Plugboard.o Reflector.o Rotor.o Pipeline.o Enigma.o
	g++ $^ -o $@

Main.o: Main.cpp 
	g++ -c $^ -o $@

Enigma.o: Enigma.cpp 
	g++ -c $^ -o $@

Pipeline.o: Pipeline.cpp 
	g++ -c $^ -o $@

Plugboard.o: Plugboard.cpp 
	g++ -c $^ -o $@

Reflector.o: Reflector.cpp
	g++ -c $^ -o $@

Rotor.o: Rotor.cpp
	g++ -c $^ -o $@

clean:
	rm -rf enigma *.o

.PHONY: clean
