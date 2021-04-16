all:start


start: main.o hashfinder.o hashstorage.o
	mkdir -p bin
	g++ -o bin/hashstation main.o hashfinder.o
	rm *.o

main.o:main.cpp
	g++ -c main.cpp

hashfinder.o:hashfinder.cpp hashfinder.h
	g++ -c hashfinder.cpp

hashstorage.o:hashstorage.cpp hashstorage.h
	g++ -c hashstorage.cpp

