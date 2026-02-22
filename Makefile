CXX = g++
CXXFLAGS = -g -Wall

TARGET = main
OBJECTS = main.o FifoQueue.o Pqueue.o simulator.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.cpp FifoQueue.hpp Pqueue.hpp simulator.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

FifoQueue.o: FifoQueue.cpp FifoQueue.hpp
	$(CXX) $(CXXFLAGS) -c FifoQueue.cpp
Pqueue.o : Pqueue.cpp Pqueue.hpp
	$(CXX) $(CXXFLAGS) -c Pqueue.cpp
simulation.o : simulator.cpp simulator.hpp
	$(CXX) $(CXXFLAGS) -c simulator.cpp
run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)