#  Przemyslaw Stawczyk 293153
#  Wiktor Kusmirek
#  third exercise
#
# TODO ~ do sth to make debug, extra_debug, relase subfolders working
#      ~ [on hold - currently removed from code]

CC := g++ # This is the main compiler

SRCDIR := src
INCDIR := include
BUILDDIR := build
TARGETDIR := bin
TARGET := zad-3
TESTDIR := test
TEST := $(TARGET)-test
CFLAGS := -std=c++11

debug: CFLAGS += -g -DDEBUG -Wall -Wextra -Wundef -pedantic
#debug: SUBDIR :=debug
debug: $(TARGET) $(TEST)

extra_debug: CFLAGS += -Wall -Wextra -Wundef -pedantic
#extra_debug: SUBDIR := extra_debug
extra_debug: $(TARGET) $(TEST)

relase: CFLAGS += -O3
#relase: SUBDIR := relase
relase: $(TARGET)

test: $(TEST)
SRCEXT := cpp
INCEXT := hpp
TESTEXT := test
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/target/%,$(SOURCES:.$(SRCEXT)=.o))
INC := -I$(INCDIR)
TESTSRC := $(shell find $(TESTDIR) -type f -name *.$(SRCEXT))
TESTOBJ := $(patsubst $(TESTDIR)/%,$(BUILDDIR)/test/%,$(TESTSRC:.$(SRCEXT)=.o))

$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	@echo " Linking target..."
	@echo " $(CC) -o $(TARGETDIR)/$(TARGET) $(LIB) $^"; $(CC) -o $(TARGETDIR)/$(TARGET) $(LIB) $^

$(BUILDDIR)/target/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)/target
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(TEST): $(TESTOBJ) $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	@echo " Linking test..."
	@echo " $(CC) -o $(TARGETDIR)/$(TEST) $(LIB) $^"; $(CC) -o $(TARGETDIR)/$(TEST) $(LIB) $^

$(BUILDDIR)/test/%.o: $(TESTDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)/test
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

purge:
	@echo " Making a purge...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET) $(TARGETDIR)"; $(RM) -r $(BUILDDIR) $(TARGET) $(TARGETDIR)

clean:
	@echo " Cleaning *.o files...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)
