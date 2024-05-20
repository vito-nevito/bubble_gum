CFLAGS = -c -Wall
SOURCES = Puzir.cpp Room.cpp postPr.cpp prePr.cpp action.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = puzir

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES) main.cpp $(OBJECTS) main.o
	g++ $(OBJECTS) main.o -o $@

.cpp.o:
	g++ $(CFLAGS) $< -o $@

vortex: $(SOURCES) vortex.cpp $(OBJECTS) vortex.o
	g++ $(OBJECTS) vortex.o -o $@

clean:
	rm *.o

cleanData:
	rm ./visP/*.csv ./visS/*.py ./visP/info ./visP/bubble.gif
