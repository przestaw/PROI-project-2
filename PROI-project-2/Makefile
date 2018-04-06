#PROI, Lab project 2: 'Theater'
#Kamil Zacharczuk
#
#THIS MAKEFILE PROBABLY DOES NOT WORK

CC = g++

BINDIR = ./bin
BUILDDIR = ./build
INCDIR = ./include
SRCDIR = ./src
TESTDIR = ./test

QUEUEHPP = $(INCDIR)/Queue.hpp
THEATERHPP = $(INCDIR)/theater.hpp
THEATERCPP = $(SRCDIR)/theater.cpp
TEST2CPP = $(TESTDIR)/test2.cpp

THEATERO = $(BUILDDIR)/theater.o
TEST2O = $(BUILDDIR)/test2.o
TARGET = $(BINDIR)/test2

HEADERS  = $(QUEUEHPP) $(THEATERHPP)


$(TARGET): $(THEATERO) $(TEST2O)
	$(CC) -o $(TARGET) $(THEATERO) $(TEST2O)

$(TEST2O): $(TEST2CPP)
	$(CC) -o $(TEST2O) -c $(TEST2CPP) -I $(INCDIR)/
	
$(THEATERO): $(THEATERCPP)
	$(CC) -o $(THEATERO) -c $(THEATERCPP) -I $(INCDIR)/

.PHONY: clean

clean:
	rm -f $(BUILDDIR)/*.o $(TARGET) *~ core 
