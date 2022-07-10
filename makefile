output: main.o log.o multithread.o
	g++ -Wall -Iincludes -lpthread main.o log.o multithread.o -o output

main.o: main.cpp
	g++ -c main.cpp
 
log.o: log.cpp
	g++ -c log.cpp

multithread.o: multithread.cpp
	g++ -c multithread.cpp

includes = $(include/*.hpp)

clean:
	rm *.o output
