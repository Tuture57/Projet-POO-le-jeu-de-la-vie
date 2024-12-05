CXX = clang++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRCS = main.cpp src/file.cpp src/position.cpp src/game.cpp src/cell.cpp src/grid.cpp src/graphic.cpp
OBJS = $(SRCS:.cpp=.o)

INCLUDES = -Iinclude

TARGET = game

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean