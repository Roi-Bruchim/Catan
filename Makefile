CXX = clang++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = 

SRCS = main.cpp Player.cpp Board.cpp Catan.cpp Tile.cpp Road.cpp Settlement.cpp
OBJS = $(SRCS:.cpp=.o)

TEST_SRCS = test.cpp Player.cpp Board.cpp Catan.cpp Tile.cpp Road.cpp Settlement.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

TARGET = catan
TEST_TARGET = test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET) $(TEST_TARGET)

run_tests: $(TEST_TARGET)
	./$(TEST_TARGET)

.PHONY: clean all run_tests
