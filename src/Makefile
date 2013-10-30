GCC=g++
GCCFLAGS=-std=c++0x -Wall -Wextra -pedantic

RESULT=aco
ACO=aco
PARSER=parameters_parser
GRAPH=graph
GRAPH_PARSER=graph_parser
FILES=$(ACO).cc $(PARSER).o $(GRAPH).o $(GRAPH_PARSER).o

all: $(RESULT)

$(RESULT): $(FILES)
	$(GCC) $(GCCFLAGS) $(FILES) -o $@

$(PARSER).o: $(PARSER).cc
	$(GCC) $(GCCFLAGS) $(PARSER).cc -c

$(GRAPH).o: $(GRAPH).cc
	$(GCC) $(GCCFLAGS) $(GRAPH).cc -c

$(GRAPH_PARSER).o: $(GRAPH_PARSER).cc
	$(GCC) $(GCCFLAGS) $(GRAPH_PARSER).cc -c

clean:
	rm *.o aco
