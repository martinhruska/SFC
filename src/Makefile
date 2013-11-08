GCC=g++
GCCFLAGS=-std=c++0x -Wall -Wextra -pedantic

RESULT=aco
ACO=aco
PARSER=parameters_parser
GRAPH=graph
GRAPH_PARSER=graph_parser
VERTEX=vertex
EDGE=edge
ANT=ant
ANT_POP=ant_population
FILES=$(ACO).cc $(PARSER).o $(GRAPH).o $(GRAPH_PARSER).o $(VERTEX).o $(EDGE).o $(ANT).o $(ANT_POP).o

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

$(ANT).o: $(ANT).cc
	$(GCC) $(GCCFLAGS) $(ANT).cc -c

$(EDGE).o: $(EDGE).cc
	$(GCC) $(GCCFLAGS) $(EDGE).cc -c

$(ANT_POP).o: $(ANT_POP).cc
	$(GCC) $(GCCFLAGS) $(ANT_POP).cc -c

clean:
	rm *.o aco
