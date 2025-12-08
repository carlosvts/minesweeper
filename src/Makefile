TARGET = minesweeper

GXX = g++

CXXFLAGS = -Wall -g -std=c++17

SRCS = main.cpp board.cpp cell.cpp
OBJS = $(patsubst %.cpp, %.o, $(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

main.o: board.h constants.h
board.o: board.h cell.h constants.h
cell.o: cell.h

# clears all ""trash"" files
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)