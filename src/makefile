# edit this makefile so that running make compiles your enigma program
INC=-I $(shell pwd)
GCC=g++
FLAGS=-std=c++11 $(INC)

enigma: Main.o Plugboard.o Reflector.o Rotor.o Pipeline.o Enigma.o Parser.o Component.o
	$(GCC) $(FLAGS) $^ -o $@

tests: Tests.o Plugboard.o Reflector.o Rotor.o Pipeline.o Enigma.o Component.o
	$(GCC) $(FLAGS) $^ -o $@

Tests.o: test/IntegrationTest.cpp
	$(GCC) $(FLAGS) -c $^ -o $@

Main.o: Main.cpp
	$(GCC) $(FLAGS) -c $^ -o $@

Enigma.o: machine/Enigma.cpp
	$(GCC) $(FLAGS) -c $^ -o $@

Pipeline.o: components/Pipeline.cpp
	$(GCC) $(FLAGS) -c $^ -o $@

Plugboard.o: components/Plugboard.cpp
	$(GCC) $(FLAGS) -c $^ -o $@

Reflector.o: components/Reflector.cpp
	$(GCC) $(FLAGS) -c $^ -o $@

Rotor.o: components/Rotor.cpp
	$(GCC) $(FLAGS) -c $^ -o $@

Parser.o: Parser.cpp
	$(GCC) $(FLAGS) -c $^ -o $@

Component.o: components/Component.cpp
	$(GCC) $(FLAGS) -c $^ -o $@

clean:
	rm -rf enigma *.o

.PHONY: clean
