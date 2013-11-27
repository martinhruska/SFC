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
ACO_ALG=aco_algorithm
RANDOM=random_provider
AS_IMPL=as_implementation
AS_DENS=as_density
AS_QUANTITY=as_quantity
FILES=$(ACO).cc $(PARSER).o $(GRAPH).o $(GRAPH_PARSER).o $(VERTEX).o $(EDGE).o $(ANT).o $(ANT_POP).o $(ACO_ALG).o $(RANDOM).o $(AS_IMPL).o $(AS_DENS).o $(AS_QUANTITY).o

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

$(AS_IMPL).o: $(AS_IMPL).cc
	$(GCC) $(GCCFLAGS) $(AS_IMPL).cc -c

$(AS_DENS).o: $(AS_DENS).cc
	$(GCC) $(GCCFLAGS) $(AS_DENS).cc -c

$(AS_QUANTITY).o: $(AS_QUANTITY).cc
	$(GCC) $(GCCFLAGS) $(AS_QUANTITY).cc -c

$(ACO_ALG).o: $(ACO_ALG).cc $(AS_IMPL).o
	$(GCC) $(GCCFLAGS) $(ACO_ALG).cc -c

$(RANDOM).o: $(RANDOM).cc
	$(GCC) $(GCCFLAGS) $(RANDOM).cc -c


clean:
	rm *.o aco
