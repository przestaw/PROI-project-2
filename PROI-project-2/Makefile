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
CFLAGS := -std=c++11

debug: CFLAGS += -g -DDEBUG -Wall -Wextra -Wundef -pedantic
#debug: SUBDIR :=debug
debug: $(TARGET)

extra_debug: CFLAGS += -Wall -Wextra -Wundef -pedantic
#extra_debug: SUBDIR := extra_debug
extra_debug: $(TARGET)

relase: CFLAGS += -O3
#relase: SUBDIR := relase
relase: $(TARGET)

SRCEXT := cpp
INCEXT := hpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
INC := -I$(INCDIR)

$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	@echo " Linking..."
	@echo " $(CC) -o $(TARGETDIR)/$(TARGET) $(LIB) $^"; $(CC) -o $(TARGETDIR)/$(TARGET) $(LIB) $^

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo " $(CC) $(CFLAGS) $(INC) -c -o $@ $<"; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

purge:
	@echo " Making a purge...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET) $(TARGETDIR)"; $(RM) -r $(BUILDDIR) $(TARGET) $(TARGETDIR)

clean:
	@echo " Cleaning *.o files...";
	@echo " $(RM) -r $(BUILDDIR) $(TARGET)"; $(RM) -r $(BUILDDIR) $(TARGET)
