#ifndef ACO_GRAPH_PARSER
#define ACO_GRAPH_PARSER

// standard libraries
#include <fstream>
#include <string>

// ACO libraries
#include "graph.hh"

namespace ACO
{
  class GraphParser;
}

class ACO::GraphParser
{
private: // private data types
  typedef std::string String;

private: // private constants
  const String e_cannotRead = "Vstupni soubor nelze cist";
  const String e_badFormat = "Soubor porusuje vstupni format: ";
  const String e_warning =
    "POZOR!!!: Tato hrana jiz byla definovana a bude ignorovana";

public: // public methods
  GraphParser() {}
  void parseGraphFromFile(std::ifstream& graphFile, Graph& graph);

private: // private methods
  void parseFormatedLine(String& line, Graph& graph);
  void addTransitionToGraph(String& node1, String& node2,
      Graph::Distance distance, Graph& graph);
};

#endif
