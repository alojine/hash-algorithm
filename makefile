run: main.o	hash.o app.o time.o
	g++ -o run main.o -O3

main.o: main.cpp
	g++ -c main.cpp

hash.o: Hash/hash.cpp
	g++ -c Hash/hash.cpp

app.o: App/app.cpp
	g++ -c App/app.cpp

time.o: Time/time.cpp
	g++ -c Time/time.cpp

clean: del *.o run.exe