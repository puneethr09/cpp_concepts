CXX = g++
CXXFLAGS = -Wall -std=c++14 -Iincludes
LDFLAGS = -lpthread

all: output

output: main.o log.o multithread.o
	$(CXX) $(CXXFLAGS) main.o log.o multithread.o $(LDFLAGS) -o output

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

log.o: log.cpp
	$(CXX) $(CXXFLAGS) -c log.cpp

multithread.o: multithread.cpp
	$(CXX) $(CXXFLAGS) -c multithread.cpp

clean:
	rm -f *.o output
