### Enigma

#### Description

The Enigma machines were a series of electro-mechanical rotor cipher machines developed and used in the early- to mid-20th century to protect commercial, diplomatic and military communication. Enigma was invented by the German engineer Arthur Scherbius at the end of World War I.

![ ](https://upload.wikimedia.org/wikipedia/commons/thumb/b/bd/Enigma_%28crittografia%29_-_Museo_scienza_e_tecnologia_Milano.jpg/330px-Enigma_%28crittografia%29_-_Museo_scienza_e_tecnologia_Milano.jpg)

This is a simple Enigma emulator which supports plugboard and rotor files and has a default reflector plugged in. Other components are easily pluggable by defining a new machine model(see `Machine.hpp` and `Enigma.hpp`) and new components(see `Component.hpp`).

#### Runnning

To run the testsuite:
```
make test
```

To run the program:
```
make
./enigma <plugboard_files> <rotor_files>
```

The input supported is upper case chars and spaces. To stop the input stream press CTRL + D. The message that you see will be the encoded message.

##### Configuration files
The configuration files are of 2 types:
* plugboard - the plugboard is made out of consecutive pairs of numbers that describe the plugboard connections
* rotor - the rotor describes the shift for each character

There are sample rotor configuration files in `rotors/` and plugboard configuration files in `plugboards/`.
