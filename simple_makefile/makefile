## Simle version:
# myProgram: main.o function.o
# 	g++ main.o function.o -o myProgram

# main.o functino.o: main.cpp function.cpp
# 	g++ -c main.cpp -o main.o
# 	g++ -c function.cpp -o function.o

# clean:
# 	rm -rf main.o function.o myProgram




## Advanced version:
# Compiler and compiler flags
CXX = g++
CXXFLAGS = -Wall -std=c++11

# Target executable
TARGET = myProgram

SRCS =  main.cpp function.cpp
OBJS = $(SRCS:.cpp=.o)

#Default target:
all: $(TARGET)


# Rule to link object file to crate target file
$(TARGET) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Rule to comile source file to object file
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(TARGET) $(OBJS)

# Phony targets
.PHONY: all clean






