run: main.o	hash.o
	g++ -o run main.o -O3

main.o: main.cpp
	g++ -c main.cpp

hash.o: hash.cpp
	g++ -c hash.cpp

clean: del *.o run.exe