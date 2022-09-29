CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g -Wall
CFLAGS=-Isrc/FileInfoUtils.h


SOURCES := src/main.cpp src/FileInfoUtils.cpp
OBJS := $(SOURCES:.cpp=.o)

all: PassProtector

PassProtector: $(OBJS)
	$(CXX) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $(OBJS)

main.o: src/main.cpp src/FileInfoUtils.h

FileInfoUtils.o: src/FileInfoUtils.h src/FileInfoUtils.cpp

clean:
	$(RM) $(OBJS)