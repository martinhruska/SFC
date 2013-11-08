GCC=g++
GCCFLAGS=-std=c++0x -Wall -Wextra -pedantic

RESULT=aco
ACO=aco
PARSER=parameters_parser
GRAPH=graph
GRAPH_PARSER=graph_parser
VERTEX=vertex
EDGE=edge
FILES=$(ACO).cc $(PARSER).o $(GRAPH).o $(GRAPH_PARSER).o $(VERTEX).o $(EDGE).o

all: $(RESULT)

$(RESULT): $(FILES)
	$(GCC) $(GCCFLAGS) $(FILES) -o $@

$(PARSER).o: $(PARSER).cc
	$(GCC) $(GCCFLAGS) $(PARSER).cc -c

$(GRAPH).o: $(GRAPH).cc
	$(GCC) $(GCCFLAGS) $(GRAPH).cc -c

$(GRAPH_PARSER).o: $(GRAPH_PARSER).cc
	$(GCC) $(GCCFLAGS) $(GRAPH_PARSER).cc -c

$(VERTEX).o: $(VERTEX).cc
	$(GCC) $(GCCFLAGS) $(VERTEX).cc -c

$(EDGE).o: $(EDGE).cc
	$(GCC) $(GCCFLAGS) $(EDGE).cc -c

clean:
	rm *.o aco
