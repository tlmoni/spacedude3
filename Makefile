CC=g++
SFML=SFML-2.4
CPPFLAGS=-c -g -std=c++17 -Wall -Wextra -pedantic -I $(SFML)/include
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network

SRCEXT=cpp
SRCDIR=src
BUILDDIR=build
BINDIR=$(BUILDDIR)/bin
SOURCES=$(shell find $(SRCDIR) -name '*.$(SRCEXT)' | sort -k 1nr | cut -f2-)
OBJECTS=$(SOURCES:$(SRCDIR)/%.$(SRCEXT)=$(BUILDDIR)/%.o)
#SOURCES:=$(wildcard *.cpp)
#OBJECTS:=$(patsubst %.cpp,%.o,$(wildcard *.cpp))
EXECUTABLE=BrawlStars

default_target: release

release: export FLAGS := $(FLAGS) $(CPPFLAGS)
release: dirs
		@$(MAKE) all

dirs:
	@mkdir -p $(dir $(OBJECTS))
	@mkdir -p $(BINDIR)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

all: $(BINDIR)/$(EXECUTABLE)
	@$(RM) $(EXECUTABLE)
	@ln -s $(BINDIR)/$(EXECUTABLE) $(EXECUTABLE)

$(BINDIR)/$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	$(CC) $(CPPFLAGS) -c $< -o $@	

run:
	make all
	./BrawlStars

#all:
#	$(SOURCES) $(EXECUTABLE)
  
#$(EXECUTABLE): $(OBJECTS) 
#	$(CC) $(OBJECTS) $(LDFLAGS) -o $@ 

#.cc.o:
#	$(CC) $(CPPFLAGS) $< -o $@

#clean:
#	rm -f $(OBJECTS) $(EXECUTABLE)

#run: BrawlStars
#	./BrawlStars