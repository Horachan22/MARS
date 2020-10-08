VPATH = src
CC = g++
CFLAGS = -g -Wall -std=c++17
SRCS = $(wildcard src/*.cpp)
DEPS = $(wildcard src/*.hpp)
OBJS = $(wildcard *.o)
TARGET = MARS

%.o: %.cpp
	@$(CC) $(CFLAGS) -o $@ -c $<

%.o: %.hpp

ALL: $(OBJS)
	@$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

clean:
	@rm -rf $(OBJS) $(TARGET)

run:
	@./$(TARGET) < $(TARGET)

build_run:
	@make compile
	@make run
