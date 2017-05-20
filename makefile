CC=g++
CC_FLAGS=-Wall -Werror -ansi -pedantic
BINDIR=exec

EXEC=OverLog
SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(SOURCES: .cpp=.o)

$(EXEC): $(OBJECTS)
	$ mkdir -p $(BINDIR)
	$(CC) $(OBJECTS) -o $(BINDIR)/$(EXEC)

%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

