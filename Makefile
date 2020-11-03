## Variables ..........................................................................:
CC= gcc -Wno-narrowing
CFLAGS= -Wall -g
LDFLAGS= -lraylib

## File directory .....................................................................:
SRCDIR= src
HEADDIR= include
OBJDIR= object
BINDIR= bin

## Project structure ..................................................................:
EXEC= bwallows
SRC= $(wildcard $(SRCDIR)/*.c)
OBJ= $(SRC:$(SRCDIR)/*.c=$(OBJDIR)/*.o)

## Launching ..........................................................................:
run: all
	@$(BINDIR)/./$(EXEC)

## Compilation ........................................................................:
all: $(EXEC)

$(EXEC): $(OBJ)
	@$(CC) -g -o $(BINDIR)/$@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADDIR)/%.h
	@$(CC) -o $@ -c $< $(CFLAGS)

## Object cleaning ....................................................................:
clean:
	@rm $(OBJDIR)/*.o

## Executable cleaning ................................................................:
Clean:clean
	@rm $(BINDIR)/*

## Archiving ..........................................................................:
tar:
	tar -zcvf ../Bwalllows.tar.gz *