DIRECTORIES=obj bin
SRCS=$(wildcard src/*.cpp)
OBJS := $(addprefix obj/,$(notdir $(SRCS:.cpp=.o)))
EXECUTABLE=bin/hackme

CPPFLAGS=-Iinclude/

all: $(DIRECTORIES) $(OBJS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $@

$(DIRECTORIES): 
	mkdir $(DIRECTORIES)

obj/%.o: src/%.cpp $(DIRECTORIES)
	$(CXX) $(CPPFLAGS) -c -o $@ $<

clean:
	-rm -rf obj
	-rm -rf bin
