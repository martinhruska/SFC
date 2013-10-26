GCC=g++
GCCFLAGS=-std=c++0x -Wall -Wextra -pedantic

RESULT=aco
ACO=aco
PARSER=parameters_parser
FILES=$(ACO).cc $(PARSER).o

all: $(RESULT)

$(RESULT): $(FILES)
	$(GCC) $(GCCFLAGS) $(FILES) -o $@

$(PARSER).o: $(PARSER).cc
	$(GCC) $(GCCFLAGS) $(PARSER).cc -c

clean:
	rm *.o aco
