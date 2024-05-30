#roibr23@gmail.com 322695883

CXX = clang++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS =

SRCS = main.cpp Player.cpp Board.cpp KnightCard.cpp VictoryPointCard.cpp Catan.cpp Tile.cpp Road.cpp Settlement.cpp
OBJS = $(SRCS:.cpp=.o)

TARGET = catan

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
