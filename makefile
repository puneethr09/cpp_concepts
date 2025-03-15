CXX = g++
CXXFLAGS = -Wall -std=c++14 -Iincludes
LDFLAGS = -lpthread

all: output

output: main.o log.o multithread.o
	$(CXX) $(CXXFLAGS) main.o log.o multithread.o $(LDFLAGS) -o output

main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp

log.o: src/log.cpp
	$(CXX) $(CXXFLAGS) -c src/log.cpp

multithread.o: src/multithread.cpp
	$(CXX) $(CXXFLAGS) -c src/multithread.cpp

clean:
	rm -f *.o output
