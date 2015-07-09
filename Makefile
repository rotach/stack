SRC=src
INC=include
LIB=.
BUILD=build
BIN=bin

CC=gcc
CCFLAGS=-I$(INC) -Wall -O
LDFLAGS=-L$(LIB) #-lxyz
AR=ar

c: $(BIN)/stack

$(BIN)/stack: stack.o
	$(CC) $(BUILD)/stack.o -o $(BIN)/stack $(LDFLAGS)

stack.o: $(SRC)/stack.c $(INC)/stack.h
	$(CC) $(CCFLAGS) -c $(SRC)/stack.c -o $(BUILD)/stack.o

all: c

clean:
	rm -f $(BUILD)/*.o
	rm -f $(BIN)/*
