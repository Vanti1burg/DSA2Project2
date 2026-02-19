CXX = g++
CXXFLAGS = -g -Wall

TARGET = main
OBJECTS = main.o FifoQueue.o Pqueue.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.cpp FifoQueue.hpp Pqueue.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

FifoQueue.o: FifoQueue.cpp FifoQueue.hpp
	$(CXX) $(CXXFLAGS) -c FifoQueue.cpp
Pqueue.o : Pqueue.cpp Pqueue.hpp
	$(CXX) $(CXXFLAGS) -c Pqueue.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJECTS)