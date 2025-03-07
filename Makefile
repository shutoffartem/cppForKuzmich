CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGET = main.out
OBJS = vector.o main.o

all: $(TARGET)
#vector.o: vector.cpp
#	$(CXX) -c vector.cpp -o vector.o
#main.o: main.cpp
#	$(CXX) -c main.cpp -o main.o 
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
$(TARGET): $(OBJS) 
	$(CXX) $(OBJS) -o $(TARGET)
clean:
	rm -f $(OBJS) $(TARGET)
