CXX = clang++
CXXFLAGS = -std=c++17 -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -g -Wmost -Werror -lGL

# Makefile
# Makefile
SRCS = main.cpp src/file.cpp src/position.cpp src/game.cpp src/cell.cpp src/classic_cell.cpp src/classic_grid.cpp src/graphic_sfml.cpp src/obstacle_cell.cpp
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
	rm -rf *_out/

.PHONY: all clean