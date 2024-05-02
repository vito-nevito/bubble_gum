CFLAGS = -c -Wall
SOURCES = main.cpp D3array.cpp Puzir.cpp postPr.cpp prePr.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = puzir

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES) $(OBJECTS)
	g++ $(OBJECTS) -o $@

.cpp.o:
	g++ $(CFLAGS) $< -o $@
