CC = g++
SFML = SFML-2.4
CPPFLAGS = -c -g -std=c++17 -Wall -Wextra -pedantic -I $(SFML)/include
VPATH = src/
SOURCES := $(wildcard *.cpp)

LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lsfml-network
OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

EXECUTABLE = BrawlStars

all: $(SOURCES) $(EXECUTABLE)
  
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@ 

.cc.o:
	$(CC) $(CPPFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

run: BrawlStars
	./BrawlStars