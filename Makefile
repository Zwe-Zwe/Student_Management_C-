# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra

# Target executable
TARGET = main

# Source files
SOURCES = main.cpp student.cpp

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

# Clean up object files and executable
clean:
	rm -f $(TARGET)
