all: sources
	mv src/enigma enigma

sources:
	cd src && make enigma

test:
	cd src && make tests
	python tests.py

clean:
	cd src && make clean
	rm -rf enigma

.PHONY: clean
