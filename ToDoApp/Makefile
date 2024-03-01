# Project directories
SRCDIR := source
INCDIR := include
OBJDIR := obj
BINDIR := bin
LIBDIR := third_party

# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -I$(INCDIR)
LDFLAGS := -L$(LIBDIR)

# Find all .cpp files in the src directory, replace them with .o files in the obj directory
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Target executable
TARGET := $(BINDIR)/todo_app

# Default target
all: $(TARGET)

# Link the target using object files
$(TARGET): $(OBJECTS)
	mkdir -p $(BINDIR)
	$(CXX) $^ -o $@ $(LDFLAGS)

# Compile .cpp files to .o files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean
