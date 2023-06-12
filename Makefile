CXX = g++
CXXFLAGS = -Wall -std=c++11
INCLUDES = -I.
SOURCES = Train.cpp TrainYard.cpp main.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = trainyard

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $(OBJECTS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f *.o $(EXECUTABLE)
